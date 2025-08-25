#include "math.h"
#include "Adc_Process.h"
#include "spectra.h"

#define spectraLength 64




struct spectra spect_feeder1_a={0};
struct spectra spect_feeder1_b={0};
struct spectra spect_feeder1_c={0};

struct spectra spect_feeder2_a={0};
struct spectra spect_feeder2_b={0};
struct spectra spect_feeder2_c={0};

struct spectra spect_feeder3_a={0};
struct spectra spect_feeder3_b={0};
struct spectra spect_feeder3_c={0};

struct spectra spect_feeder4_a={0};
struct spectra spect_feeder4_b={0};
struct spectra spect_feeder4_c={0};

struct spectra spect_feeder5_a={0};
struct spectra spect_feeder5_b={0};
struct spectra spect_feeder5_c={0};


//Twiddle array for Spectral Analysis:
//for fs=3200 and sample no for period = 64 @50hz

float coeffs_real[]={
1.00000000000000000000f,
0.99518471956253051757f,0.98078525066375732421f,0.95694035291671752929f,
0.92387950420379638671f,0.88192129135131835937f,0.83146959543228149414f,
0.77301043272018432617f,0.70710676908493041992f,0.63439327478408813476f,
0.55557024478912353515f,0.47139674425125122070f,0.38268342614173889160f,
0.29028466343879699707f,0.19509032368659973144f,0.09801714122295379638f,
-0.00000000000000016081f,-0.09801714122295379638f,-0.19509032368659973144f,
-0.29028466343879699707f,-0.38268342614173889160f,-0.47139674425125122070f,
-0.55557024478912353515f,-0.63439327478408813476f,-0.70710676908493041992f,
-0.77301043272018432617f,-0.83146959543228149414f,-0.88192129135131835937f,
-0.92387950420379638671f,-0.95694035291671752929f,-0.98078525066375732421f,
-0.99518471956253051757f,-1.00000000000000000000f,-0.99518471956253051757f,
-0.98078525066375732421f,-0.95694035291671752929f,-0.92387950420379638671f,
-0.88192129135131835937f,-0.83146959543228149414f,-0.77301043272018432617f,
-0.70710676908493041992f,-0.63439327478408813476f,-0.55557024478912353515f,
-0.47139674425125122070f,-0.38268342614173889160f,-0.29028466343879699707f,
-0.19509032368659973144f,-0.09801714122295379638f,0.00000000000000070448f,
0.09801714122295379638f,0.19509032368659973144f,0.29028466343879699707f,
0.38268342614173889160f,0.47139674425125122070f,0.55557024478912353515f,
0.63439327478408813476f,0.70710676908493041992f,0.77301043272018432617f,
0.83146959543228149414f,0.88192129135131835937f,0.92387950420379638671f,
0.95694035291671752929f,0.98078525066375732421f,0.99518471956253051757f,
};

float coeffs_imag[]={
0.00000000000000000000f,
0.09801714122295379638f,0.19509032368659973144f,0.29028466343879699707f,
0.38268342614173889160f,0.47139674425125122070f,0.55557024478912353515f,
0.63439327478408813476f,0.70710676908493041992f,0.77301043272018432617f,
0.83146959543228149414f,0.88192129135131835937f,0.92387950420379638671f,
0.95694035291671752929f,0.98078525066375732421f,0.99518471956253051757f,
1.00000000000000000000f,0.99518471956253051757f,0.98078525066375732421f,
0.95694035291671752929f,0.92387950420379638671f,0.88192129135131835937f,
0.83146959543228149414f,0.77301043272018432617f,0.70710676908493041992f,
0.63439327478408813476f,0.55557024478912353515f,0.47139674425125122070f,
0.38268342614173889160f,0.29028466343879699707f,0.19509032368659973144f,
0.09801714122295379638f,-0.00000000000000032162f,-0.09801714122295379638f,
-0.19509032368659973144f,-0.29028466343879699707f,-0.38268342614173889160f,
-0.47139674425125122070f,-0.55557024478912353515f,-0.63439327478408813476f,
-0.70710676908493041992f,-0.77301043272018432617f,-0.83146959543228149414f,
-0.88192129135131835937f,-0.92387950420379638671f,-0.95694035291671752929f,
-0.98078525066375732421f,-0.99518471956253051757f,-1.00000000000000000000f,
-0.99518471956253051757f,-0.98078525066375732421f,-0.95694035291671752929f,
-0.92387950420379638671f,-0.88192129135131835937f,-0.83146959543228149414f,
-0.77301043272018432617f,-0.70710676908493041992f,-0.63439327478408813476f,
-0.55557024478912353515f,-0.47139674425125122070f,-0.38268342614173889160f,
-0.29028466343879699707f,-0.19509032368659973144f,-0.09801714122295379638f,
};


void signal_spectra(
	
	float rtInput, 
	struct spectra *h,
	unsigned int qBufferLength,		//updated buffer length
	float *twBufferReal,			//twiddle factor Real coeffs
	float *twBufferImag,			//twiddle factor Imag coeffs    
	unsigned int pCounter)

{

	float x_error;
	float temp_real,temp_imag;
	float out_scale;
	unsigned int i;

	out_scale=1.41421356237309f/(float)qBufferLength;


	x_error=h->qBuffer[pCounter]-rtInput;
	h->qBuffer[pCounter]=rtInput;

	for(i=0;i<4;i++){

	temp_real =twBufferReal[i]* (h->foutReal[i]+x_error)-twBufferImag[i]*h->foutImag[i];
	temp_imag=twBufferImag[i]* (h->foutReal[i]+x_error)+twBufferReal[i]*h->foutImag[i];

	h->foutMag[i]=out_scale*__sqrtf(temp_real*temp_real+temp_imag*temp_imag);

	h->foutReal[i]=temp_real;
	h->foutImag[i]=temp_imag;
	
	}


}



void spectra(void){
	
	
	static unsigned int count=0; 
	
	signal_spectra(ADC_Values.ICH1, &spect_feeder1_a, spectraLength, &coeffs_real[0], &coeffs_imag[0], count);
	signal_spectra(ADC_Values.ICH2, &spect_feeder1_b, spectraLength, &coeffs_real[0], &coeffs_imag[0], count);
	signal_spectra(ADC_Values.ICH3, &spect_feeder1_c, spectraLength, &coeffs_real[0], &coeffs_imag[0], count);
	
	signal_spectra(ADC_Values.ICH4, &spect_feeder2_a, spectraLength, &coeffs_real[0], &coeffs_imag[0], count);
	signal_spectra(ADC_Values.ICH5, &spect_feeder2_b, spectraLength, &coeffs_real[0], &coeffs_imag[0], count);
	signal_spectra(ADC_Values.ICH6, &spect_feeder2_c, spectraLength, &coeffs_real[0], &coeffs_imag[0], count);
	
	signal_spectra(ADC_Values.ICH7, &spect_feeder3_a, spectraLength, &coeffs_real[0], &coeffs_imag[0], count);
	signal_spectra(ADC_Values.ICH8, &spect_feeder3_b, spectraLength, &coeffs_real[0], &coeffs_imag[0], count);
	signal_spectra(ADC_Values.ICH9, &spect_feeder3_c, spectraLength, &coeffs_real[0], &coeffs_imag[0], count);
	
	signal_spectra(ADC_Values.ICH10, &spect_feeder4_a, spectraLength, &coeffs_real[0], &coeffs_imag[0], count);
	signal_spectra(ADC_Values.ICH11, &spect_feeder4_b, spectraLength, &coeffs_real[0], &coeffs_imag[0], count);
	signal_spectra(ADC_Values.ICH12, &spect_feeder4_c, spectraLength, &coeffs_real[0], &coeffs_imag[0], count);
	
	signal_spectra(ADC_Values.ICH13, &spect_feeder5_a, spectraLength, &coeffs_real[0], &coeffs_imag[0], count);
	signal_spectra(ADC_Values.ICH14, &spect_feeder5_b, spectraLength, &coeffs_real[0], &coeffs_imag[0], count);
	signal_spectra(ADC_Values.ICH15, &spect_feeder5_c, spectraLength, &coeffs_real[0], &coeffs_imag[0], count);
	
	if(++count==spectraLength){count=0;}

}


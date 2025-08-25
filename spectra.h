#ifndef SPECTRA_H
#define SPECTRA_H

struct spectra {

	float qBuffer[64];
	float foutReal[4];
	float foutImag[4];
	float foutMag[4];

};

void signal_spectra(
	
	float rtInput, 
	struct spectra *h,
	unsigned int qBufferLength,		//updated buffer length
	float *twBufferReal,			//twiddle factor Real coeffs
	float *twBufferImag,			//twiddle factor Imag coeffs    
	unsigned int pCounter);


void spectra(void);

extern struct spectra spect_feeder1_a;
extern struct spectra spect_feeder1_b;
extern struct spectra spect_feeder1_c;

extern struct spectra spect_feeder2_a;
extern struct spectra spect_feeder2_b;
extern struct spectra spect_feeder2_c;

extern struct spectra spect_feeder3_a;
extern struct spectra spect_feeder3_b;
extern struct spectra spect_feeder3_c;

extern struct spectra spect_feeder4_a;
extern struct spectra spect_feeder4_b;
extern struct spectra spect_feeder4_c;

extern struct spectra spect_feeder5_a;
extern struct spectra spect_feeder5_b;
extern struct spectra spect_feeder5_c;
#endif 

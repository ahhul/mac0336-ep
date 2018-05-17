#include "keys.h"

void sub_keys (uint32_t **KR5, uint32_t **KM32, uint32_t *K) {
	int i;
	uint32_t **Ki;
	Ki = alocation (12, 4);
	/*TODO CALCULAR INTERMEDIARIOS KI A PARTIR DE K*/
	for (i = 0; i < 12; ++i) {
		KR5[i][0] = five_bits_right (Ki[i][0]); KR5[i][1] = five_bits_right (Ki[i][1]);
		KR5[i][2] = five_bits_right (Ki[i][2]); KR5[i][3] = five_bits_right (Ki[i][3]);
		KM32[i][0] = Ki[i][3]; KM32[i][1] = Ki[i][2];
		KM32[i][2] = Ki[i][1]; KM32[i][3] = Ki[i][0];
	}
}

/*uint32_t f1 (int num, uint32_t X, uint32_t KR5, uint32_t KM32) {
	uint32_t Y, I;
	ui I, It[4];

	I = ((KM32 ^ X) << KR5) | ((KM32 ^ X) >> (32 - KR5));
	It[0] = I >> 24; It[1] = (I << 8) >> 24;
	It[2] = (I << 16) >> 24; It[3] = (I << 24) >> 24;

	switch (num) {
		case 1:
			Y = ((S1[It[0]] + S2[It[1]]) - S3[It[2]]) ^ S4[It[3]];
		break;

		case 2:
			Y = ((S1[It[0]] - S2[It[1]]) ^ S3[It[2]]) + S4[It[3]];
		break;

		default:
			Y = ((S1[It[0]] ^ S2[It[1]]) + S3[It[2]]) - S4[It[3]];
	}

	return Y;
}
*/

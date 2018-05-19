#include "keys.h"


void sub_keys (uint128_t inter_key, byte_t KR5[], uint32_t KM32[]){
	uint32_t X, Y, W, Z;
	X = inter_key.X;
	Y = inter_key.Y;
	W = inter_key.W;
	Z = inter_key.Z;

	KR5[0] = five_bits_right (X);
	KR5[1] = five_bits_right (Y);
	KR5[2] = five_bits_right (W);
	KR5[3] = five_bits_right (Z);

	KM32[0] = Z;
	KM32[1] = W;
	KM32[2] = Y;
	KM32[3] = X;
}

uint32_t f_1(uint32_t X, byte_t KR5, uint32_t KM32){
  uint32_t i, Y;
	byte_t *bytes;
	i = circular_rotation ((X ^ KM32), KR5);
  bytes = get_bytes(i);
  Y = ((sbox_1[bytes[0]] + sbox_2[bytes[1]]) - sbox_3[bytes[2]]);
  Y ^= sbox_4[bytes[3]];
  return Y;
}

uint32_t f_2(uint32_t X, byte_t KR5, uint32_t KM32){
  uint32_t i, Y;
	byte_t *bytes;
	i = circular_rotation ((X ^ KM32), KR5);
  bytes = get_bytes(i);
  Y = ((sbox_1[bytes[0]] - sbox_2[bytes[1]]) ^ sbox_3[bytes[2]]);
  Y += sbox_4[bytes[3]];
  return Y;
}

uint32_t f_3(uint32_t X, byte_t KR5, uint32_t KM32){
  uint32_t i, Y;
	byte_t *bytes;
	i = circular_rotation ((X ^ KM32), KR5);
  bytes = get_bytes(i);
  Y = ((sbox_1[bytes[0]] ^ sbox_2[bytes[1]]) + sbox_3[bytes[2]]);
  Y -= sbox_4[bytes[3]];
  return Y;
}

uint128_t intermediary_key (uint128_t K_old, int iteration){
	uint128_t inter_key, constant;
	uint32_t X, Y, W, Z;
	X = K_old.X;
	Y = K_old.Y;
	W = K_old.W;
	Z = K_old.Z;

	if (iteration == 0){
		constant.X = 0x5A827999;
		constant.Y = 0x874AA67D;
		constant.W = 0x657B7C8E;
		constant.Z = 0xBD070242;
		inter_key.X = X ^ constant.X;
		inter_key.Y = Y ^ constant.Y;
		inter_key.W = W ^ constant.W;
		inter_key.Z = Z ^ constant.Z;
	} else {
		K_old.W ^= f_2(K_old.X, circular_rotation (ConstR, fmod(pow(iteration + 2, 2), 3)), circular_rotation (ConstM, fmod(pow(iteration + 3, 2), 7)));
		K_old.Z ^= f_2(K_old.W, circular_rotation (ConstR, fmod(iteration + 2, 3)), circular_rotation (ConstM, fmod(iteration + 3, 7)));
		K_old.Y ^= f_2(K_old.Z, circular_rotation (ConstR, fmod(pow(iteration + 2, 3), 3)), circular_rotation (ConstM, fmod(pow(iteration + 3, 3), 7)));
		K_old.X ^= f_2(K_old.Y, circular_rotation (ConstR, fmod(pow(iteration + 2, 2), 3)), circular_rotation (ConstM, fmod(pow(iteration + 3, 2), 7)));
		inter_key.X = K_old.W;
		inter_key.Y = K_old.Z;
		inter_key.W = K_old.Y;
		inter_key.Z = K_old.X;
	}

	return inter_key;
}

uint128_t one_iteration (int iteration, uint128_t int_key, uint128_t value){
  uint128_t new_block;
	uint32_t X, Y, W, Z;
	uint32_t KM32[4];
  byte_t KR5[4];

	X = value.X;
  Y = value.Y;
  W = value.W;
  Z = value.Z;

	sub_keys(int_key, KR5, KM32);


  W ^= f_2(Z, KR5[0], KM32[0]);
  Y ^= f_1(W, KR5[1], KM32[1]);
  X ^= f_3(Y, KR5[2], KM32[2]);
  Z ^= f_2(X, KR5[3], KM32[3]);

  new_block.X = W;
  new_block.Y = Y;
  new_block.W = X;
  new_block.Z = Z;

  return new_block;

}

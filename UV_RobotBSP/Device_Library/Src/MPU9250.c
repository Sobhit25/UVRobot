/*
 * MPU9250.c
 *
 *  Created on: Nov 20, 2021
 *      Author: SOBHIT PANDA
 */


#include "MPU9250.h"

// MPU9250 registers

		const uint8_t MPU9250_Addr = (0x68 << 1);

		const uint8_t ACCEL_OUT = 0x3B;
		const uint8_t GYRO_OUT = 0x43;
		const uint8_t TEMP_OUT = 0x41;
		const uint8_t EXT_SENS_DATA_00 = 0x49;

		const uint8_t ACCEL_CONFIG = 0x1C;
//#define ACCEL_FS_SEL_2G  0x00
		const uint8_t ACCEL_FS_SEL_4G = 0x08;
		const uint8_t ACCEL_FS_SEL_8G = 0x10;
		const uint8_t ACCEL_FS_SEL_16G = 0x18;

		const uint8_t GYRO_CONFIG = 0x1B;
//#define GYRO_FS_SEL_250DPS  0x00
		const uint8_t GYRO_FS_SEL_500DPS = 0x08;
		const uint8_t GYRO_FS_SEL_1000DPS = 0x10;
		const uint8_t GYRO_FS_SEL_2000DPS = 0x18;

		const uint8_t ACCEL_CONFIG2 = 0x1D;
		const uint8_t ACCEL_DLPF_184 = 0x01;
		const uint8_t ACCEL_DLPF_92 = 0x02;
		const uint8_t ACCEL_DLPF_41 = 0x03;
		const uint8_t ACCEL_DLPF_20 = 0x04;
		const uint8_t ACCEL_DLPF_10 = 0x05;
		const uint8_t ACCEL_DLPF_5 = 0x06;
		const uint8_t ACCEL_DLPF_OFF = 0x00; // 460 Hz BW - OBS. Very important not to use 0x07 even though the datasheet says it is to be possible !!!

		const uint8_t CONFIG = 0x1A;
//#define GYRO_DLPF_250  0x00
		const uint8_t GYRO_DLPF_184 = 0x01;
		const uint8_t GYRO_DLPF_92 = 0x02;
		const uint8_t GYRO_DLPF_41 = 0x03;
		const uint8_t GYRO_DLPF_20 = 0x04;
		const uint8_t GYRO_DLPF_10 = 0x05;
		const uint8_t GYRO_DLPF_5 = 0x06;
		const uint8_t GYRO_DLPF_OFF = 0x07; // 3600 Hz BW

		const uint8_t SMPDIV = 0x19;

		const uint8_t INT_PIN_CFG = 0x37;
		const uint8_t INT_ENABLE = 0x38;
		const uint8_t INT_DISABLE = 0x00;
		const uint8_t INT_PULSE_50US = 0x00;
		const uint8_t INT_RAW_RDY_EN = 0x01;

		const uint8_t PWR_MGMNT_1 = 0x6B;
		const uint8_t PWR_RESET = 0x80;
		const uint8_t CLOCK_SEL_PLL = 0x01;

		const uint8_t PWR_MGMNT_2 = 0x6C;
		const uint8_t SEN_ENABLE = 0x00;

		const uint8_t SELF_TEST_X_GYRO = 0x00;
		const uint8_t SELF_TEST_Y_GYRO = 0x01;
		const uint8_t SELF_TEST_Z_GYRO = 0x02;

		const uint8_t SELF_TEST_X_ACCEL = 0x0D;
		const uint8_t SELF_TEST_Y_ACCEL = 0x0E;
		const uint8_t SELF_TEST_Z_ACCEL = 0x0F;

		const uint8_t SELF_TEST_A = 0x10;

		const uint8_t USER_CTRL = 0x6A;
		const uint8_t I2C_MST_EN = 0x20;
		const uint8_t I2C_MST_CLK = 0x0D;
		const uint8_t I2C_MST_CTRL = 0x24;
		const uint8_t I2C_SLV0_ADDR = 0x25;
		const uint8_t I2C_SLV0_REG = 0x26;
		const uint8_t I2C_SLV0_DO = 0x63;
		const uint8_t I2C_SLV0_CTRL = 0x27;
		const uint8_t I2C_SLV0_EN = 0x80;
		const uint8_t I2C_READ_FLAG = 0x80;

		const uint8_t WHO_AM_I = 0x75;

		// AK8963 registers
		const uint8_t AK8963_I2C_ADDR = 0x0C;

		const uint8_t AK8963_HXL = 0x03;

		const uint8_t AK8963_CNTL1 = 0x0A;
		const uint8_t AK8963_PWR_DOWN = 0x00;
		const uint8_t AK8963_CNT_MEAS1 = 0x12;
		const uint8_t AK8963_CNT_MEAS2 = 0x16;
		const uint8_t AK8963_FUSE_ROM = 0x0F;

		const uint8_t AK8963_CNTL2 = 0x0B;
		const uint8_t AK8963_RESET = 0x01;

		const uint8_t AK8963_ASA = 0x10;

		const uint8_t AK8963_WHO_AM_I = 0x00;


/**
  * @brief  Register Configuration of MPU9250
  * @param  none
  * @retval none
  */
void MPU9250_Initialisation(MPU9250_t *mpu9250, I2C_HandleTypeDef *hi2c){
	uint8_t *pData = 0x00;
	HAL_I2C_Mem_Write(hi2c, MPU9250_Addr, PWR_MGMNT_1, 1, pData, 1, HAL_MAX_DELAY);

	*pData = mpu9250->accel_range;
	HAL_I2C_Mem_Write(hi2c, MPU9250_Addr, ACCEL_CONFIG, 1, pData, 1, HAL_MAX_DELAY);

	*pData = mpu9250->gyro_range;
	HAL_I2C_Mem_Write(hi2c, MPU9250_Addr, GYRO_CONFIG, 1, pData, 1, HAL_MAX_DELAY);

	*pData = 0x07;
	HAL_I2C_Mem_Write(hi2c, MPU9250_Addr, SMPDIV, 1, pData, 1, HAL_MAX_DELAY);
	*pData = mpu9250->dlpf_bandwidth;
	HAL_I2C_Mem_Write(hi2c, MPU9250_Addr, CONFIG, 1, pData, 1, HAL_MAX_DELAY);

}
void Get_Raw_Gyro(MPU9250_t *mpu9250, I2C_HandleTypeDef *hi2c){
	uint8_t buffer[6];
	HAL_I2C_Mem_Read(hi2c, MPU9250_Addr, ACCEL_OUT, 1, buffer, 6, HAL_MAX_DELAY);

    mpu9250->Acc_X_RAW = (buffer[1] << 1) | buffer[0];
    mpu9250->Acc_Y_RAW = (buffer[3] << 1) | buffer[2];
    mpu9250->Acc_Z_RAW = (buffer[5] << 1) | buffer[4];
}
void Get_Raw_Accel(MPU9250_t *mpu9250, I2C_HandleTypeDef *hi2c){

}
void Get_Temperature(MPU9250_t *mpu9250, I2C_HandleTypeDef *hi2c){

}
void Get_Raw_Compass(MPU9250_t *mpu9250, I2C_HandleTypeDef *hi2c){

}
void Get_All(MPU9250_t *mpu9250, I2C_HandleTypeDef *hi2c){

}

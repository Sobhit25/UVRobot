/*
 * MPU9250.h
 *
 *  Created on: Nov 20, 2021
 *      Author: SOBHIT PANDA
 */


#ifndef INC_MPU9250_H_
#define INC_MPU9250_H_

#include "stdint.h"
#include "main407.h"

typedef struct
{
	uint8_t gyro_range;
	uint8_t accel_range;
	uint8_t dlpf_bandwidth;

    int16_t Acc_X_RAW;
    int16_t Acc_Y_RAW;
    int16_t Acc_Z_RAW;

    int16_t Gyro_X_RAW;
    int16_t Gyro_Y_RAW;
    int16_t Gyro_Z_RAW;

    int16_t	Temp_RAW;

}MPU9250_t;

#define ACCEL_FS_SEL_2G  0x00
#define GYRO_FS_SEL_250DPS  0x00
#define GYRO_DLPF_250  0x00

void MPU9250_Initialisation(MPU9250_t *mpu9250, I2C_HandleTypeDef *hi2c);
void Get_Raw_Gyro(MPU9250_t *mpu9250, I2C_HandleTypeDef *hi2c);
void Get_Raw_Accel(MPU9250_t *mpu9250, I2C_HandleTypeDef *hi2c);
void Get_Temperature(MPU9250_t *mpu9250, I2C_HandleTypeDef *hi2c);
void Get_Raw_Compass(MPU9250_t *mpu9250, I2C_HandleTypeDef *hi2c);
void Get_All(MPU9250_t *mpu9250, I2C_HandleTypeDef *hi2c);

/*
typedef enum mpu9250_gyro_range
{
	GYRO_RANGE_250DPS,
	GYRO_RANGE_500DPS,
	GYRO_RANGE_1000DPS,
	GYRO_RANGE_2000DPS
} Gyro_range;

typedef enum mpu9250_accel_range
{
	ACCEL_RANGE_2G,
	ACCEL_RANGE_4G,
	ACCEL_RANGE_8G,
	ACCEL_RANGE_16G
} Accel_range;

typedef enum mpu9250_dlpf_bandwidth
{
	DLPF_BANDWIDTH_250HZ,
	DLPF_BANDWIDTH_184HZ,
	DLPF_BANDWIDTH_92HZ,
	DLPF_BANDWIDTH_41HZ,
	DLPF_BANDWIDTH_20HZ,
	DLPF_BANDWIDTH_10HZ,
	DLPF_BANDWIDTH_5HZ,
	DLPF_BANDWIDTH_OFF
} DLPF_bandwidth;

*/




#endif /* INC_MPU9250_H_ */

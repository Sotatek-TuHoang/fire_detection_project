#ifndef __BME680_REG_DEF_H__
#define __BME680_REG_DEF_H__

// modes
#define BME680_SLEEP_MODE           0x00    // low power sleeping
#define BME680_FORCED_MODE          0x01    // perform one TPHG cycle (field data 0 filled)
#define BME680_PARALLEL_MODE        0x02
#define BME680_SQUENTUAL_MODE       0x02 

// register addresses
#define BME680_REG_RES_HEAT_VAL     0x00
#define BME680_REG_RES_HEAT_RANGE   0x02
#define BME680_REG_RANGE_SW_ERROR   0x06

#define BME680_REG_IDAC_HEAT_BASE   0x50    // 10 regsrs idac_heat_0 ... idac_heat_9
#define BME680_REG_RES_HEAT_BASE    0x5a    // 10 registers res_heat_0 ... res_heat_9
#define BME680_REG_GAS_WAIT_BASE    0x64    // 10 registers gas_wait_0 ... gas_wait_9
#define BME680_REG_CTRL_GAS_0       0x70
#define BME680_REG_CTRL_GAS_1       0x71
#define BME680_REG_CTRL_HUM         0x72
#define BME680_REG_STATUS           0x73
#define BME680_REG_CTRL_MEAS        0x74
#define BME680_REG_CONFIG           0x75
#define BME680_REG_ID               0xd0
#define BME680_REG_RESET            0xe0

// field data 0 registers
#define BME680_REG_MEAS_STATUS_0    0x1d
#define BME680_REG_MEAS_INDEX_0     0x1e
#define BME680_REG_PRESS_MSB_0      0x1f
#define BME680_REG_PRESS_LSB_0      0x20
#define BME680_REG_PRESS_XLSB_0     0x21
#define BME680_REG_TEMP_MSB_0       0x22
#define BME680_REG_TEMP_LSB_0       0x23
#define BME680_REG_TEMP_XLSB_0      0x24
#define BME680_REG_HUM_MSB_0        0x25
#define BME680_REG_HUM_LSB_0        0x26
#define BME680_REG_GAS_R_MSB_0      0x2a
#define BME680_REG_GAS_R_LSB_0      0x2b

// field data 1 registers (not documented, used in SEQUENTIAL_MODE)
#define BME680_REG_MEAS_STATUS_1    0x2e
#define BME680_REG_MEAS_INDEX_1     0x2f

// field data 2 registers (not documented, used in SEQUENTIAL_MODE)
#define BME680_REG_MEAS_STATUS_2    0x3f
#define BME680_REG_MEAS_INDEX_2     0x40

// field data addresses
#define BME680_REG_RAW_DATA_0       BME680_REG_MEAS_STATUS_0    // 0x1d ... 0x2b
#define BME680_REG_RAW_DATA_1       BME680_REG_MEAS_STATUS_1    // 0x2e ... 0x3c
#define BME680_REG_RAW_DATA_2       BME680_REG_MEAS_STATUS_2    // 0x40 ... 0x4d
#define BME680_REG_RAW_DATA_LEN     (BME680_REG_GAS_R_LSB_0 - BME680_REG_MEAS_STATUS_0 + 1)

// calibration data registers
#define BME680_REG_CD1_ADDR         0x89    // 25 byte calibration data
#define BME680_REG_CD1_LEN          25
#define BME680_REG_CD2_ADDR         0xe1    // 16 byte calibration data
#define BME680_REG_CD2_LEN          16
#define BME680_REG_CD3_ADDR         0x00    //  8 byte device specific calibration data
#define BME680_REG_CD3_LEN          8

// register structure definitions
#define BME680_NEW_DATA_BITS        0x80    // BME680_REG_MEAS_STATUS<7>
#define BME680_NEW_DATA_SHIFT       7       // BME680_REG_MEAS_STATUS<7>
#define BME680_GAS_MEASURING_BITS   0x40    // BME680_REG_MEAS_STATUS<6>
#define BME680_GAS_MEASURING_SHIFT  6       // BME680_REG_MEAS_STATUS<6>
#define BME680_MEASURING_BITS       0x20    // BME680_REG_MEAS_STATUS<5>
#define BME680_MEASURING_SHIFT      5       // BME680_REG_MEAS_STATUS<5>
#define BME680_GAS_MEAS_INDEX_BITS  0x0f    // BME680_REG_MEAS_STATUS<3:0>
#define BME680_GAS_MEAS_INDEX_SHIFT 0       // BME680_REG_MEAS_STATUS<3:0>

#define BME680_GAS_R_LSB_BITS       0xc0    // BME680_REG_GAS_R_LSB<7:6>
#define BME680_GAS_R_LSB_SHIFT      6       // BME680_REG_GAS_R_LSB<7:6>
#define BME680_GAS_VALID_BITS       0x20    // BME680_REG_GAS_R_LSB<5>
#define BME680_GAS_VALID_SHIFT      5       // BME680_REG_GAS_R_LSB<5>
#define BME680_HEAT_STAB_R_BITS     0x10    // BME680_REG_GAS_R_LSB<4>
#define BME680_HEAT_STAB_R_SHIFT    4       // BME680_REG_GAS_R_LSB<4>
#define BME680_GAS_RANGE_R_BITS     0x0f    // BME680_REG_GAS_R_LSB<3:0>
#define BME680_GAS_RANGE_R_SHIFT    0       // BME680_REG_GAS_R_LSB<3:0>

#define BME680_HEAT_OFF_BITS        0x04    // BME680_REG_CTRL_GAS_0<3>
#define BME680_HEAT_OFF_SHIFT       3       // BME680_REG_CTRL_GAS_0<3>

#define BME680_RUN_GAS_BITS         0x10    // BME680_REG_CTRL_GAS_1<4>
#define BME680_RUN_GAS_SHIFT        4       // BME680_REG_CTRL_GAS_1<4>
#define BME680_NB_CONV_BITS         0x0f    // BME680_REG_CTRL_GAS_1<3:0>
#define BME680_NB_CONV_SHIFT        0       // BME680_REG_CTRL_GAS_1<3:0>

#define BME680_SPI_3W_INT_EN_BITS   0x40    // BME680_REG_CTRL_HUM<6>
#define BME680_SPI_3W_INT_EN_SHIFT  6       // BME680_REG_CTRL_HUM<6>
#define BME680_OSR_H_BITS           0x07    // BME680_REG_CTRL_HUM<2:0>
#define BME680_OSR_H_SHIFT          0       // BME680_REG_CTRL_HUM<2:0>

#define BME680_OSR_T_BITS           0xe0    // BME680_REG_CTRL_MEAS<7:5>
#define BME680_OSR_T_SHIFT          5       // BME680_REG_CTRL_MEAS<7:5>
#define BME680_OSR_P_BITS           0x1c    // BME680_REG_CTRL_MEAS<4:2>
#define BME680_OSR_P_SHIFT          2       // BME680_REG_CTRL_MEAS<4:2>
#define BME680_MODE_BITS            0x03    // BME680_REG_CTRL_MEAS<1:0>
#define BME680_MODE_SHIFT           0       // BME680_REG_CTRL_MEAS<1:0>

#define BME680_FILTER_BITS          0x1c    // BME680_REG_CONFIG<4:2>
#define BME680_FILTER_SHIFT         2       // BME680_REG_CONFIG<4:2>
#define BME680_SPI_3W_EN_BITS       0x01    // BME680_REG_CONFIG<0>
#define BME680_SPI_3W_EN_SHIFT      0       // BME680_REG_CONFIG<0>

#define BME680_SPI_MEM_PAGE_BITS    0x10    // BME680_REG_STATUS<4>
#define BME680_SPI_MEM_PAGE_SHIFT   4       // BME680_REG_STATUS<4>

#define BME680_GAS_WAIT_BITS        0x3f    // BME680_REG_GAS_WAIT+x<5:0>
#define BME680_GAS_WAIT_SHIFT       0       // BME680_REG_GAS_WAIT+x<5:0>
#define BME680_GAS_WAIT_MULT_BITS   0xc0    // BME680_REG_GAS_WAIT+x<7:6>
#define BME680_GAS_WAIT_MULT_SHIFT  6       // BME680_REG_GAS_WAIT+x<7:6>

// commands
#define BME680_RESET_CMD            0xb6    // BME680_REG_RESET<7:0>
#define BME680_RESET_PERIOD         10      // reset time in ms

#define BME680_RHR_BITS             0x30    // BME680_REG_RES_HEAT_RANGE<5:4>
#define BME680_RHR_SHIFT            4       // BME680_REG_RES_HEAT_RANGE<5:4>
#define BME680_RSWE_BITS            0xf0    // BME680_REG_RANGE_SW_ERROR<7:4>
#define BME680_RSWE_SHIFT           4       // BME680_REG_RANGE_SW_ERROR<7:4>

// calibration data are stored in a calibration data map
#define BME680_CDM_SIZE (BME680_REG_CD1_LEN + BME680_REG_CD2_LEN + BME680_REG_CD3_LEN)
#define BME680_CDM_OFF1 0
#define BME680_CDM_OFF2 BME680_REG_CD1_LEN
#define BME680_CDM_OFF3 BME680_CDM_OFF2 + BME680_REG_CD2_LEN

// calibration parameter offsets in calibration data map
// calibration data from 0x89
#define BME680_CDM_T2   1
#define BME680_CDM_T3   3
#define BME680_CDM_P1   5
#define BME680_CDM_P2   7
#define BME680_CDM_P3   9
#define BME680_CDM_P4   11
#define BME680_CDM_P5   13
#define BME680_CDM_P7   15
#define BME680_CDM_P6   16
#define BME680_CDM_P8   19
#define BME680_CDM_P9   21
#define BME680_CDM_P10  23
// calibration data from 0e1
#define BME680_CDM_H2   25
#define BME680_CDM_H1   26
#define BME680_CDM_H3   28
#define BME680_CDM_H4   29
#define BME680_CDM_H5   30
#define BME680_CDM_H6   31
#define BME680_CDM_H7   32
#define BME680_CDM_T1   33
#define BME680_CDM_GH2  35
#define BME680_CDM_GH1  37
#define BME680_CDM_GH3  38
// device specific calibration data from 0x00
#define BME680_CDM_RHV  41      // 0x00 - res_heat_val
#define BME680_CDM_RHR  43      // 0x02 - res_heat_range
#define BME680_CDM_RSWE 45      // 0x04 - range_sw_error

#endif //__BME680_REG_DEF_H__
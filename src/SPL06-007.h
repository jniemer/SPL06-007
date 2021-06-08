#include "Arduino.h"

class SPL06 {
    private:
        static uint8_t get_spl_id();		// Get ID Register 		0x0D
        static uint8_t get_spl_prs_cfg();	// Get PRS_CFG Register	0x06
        static uint8_t get_spl_tmp_cfg();	// Get TMP_CFG Register	0x07
        static uint8_t get_spl_meas_cfg();	// Get MEAS_CFG Register	0x08
        static uint8_t get_spl_cfg_reg();	// Get CFG_REG Register	0x09
        static uint8_t get_spl_int_sts();	// Get INT_STS Register	0x0A
        static uint8_t get_spl_fifo_sts();	// Get FIFO_STS Register	0x0B

        double get_altitude(double pressure, double seaLevelhPa);	// get altitude in meters
        double get_altitude_f(double pressure, double seaLevelhPa);	// get altitude in feet

        static int16_t get_c0();
        static int16_t get_c1();
        static int32_t get_c00();
        static int32_t get_c10();
        static int16_t get_c01();
        static int16_t get_c11();
        static int16_t get_c20();
        static int16_t get_c21();
        static int16_t get_c30();

        static void i2c_eeprom_write_uint8_t(  uint8_t deviceaddress, uint8_t eeaddress, uint8_t data );
        static uint8_t i2c_eeprom_read_uint8_t(  uint8_t deviceaddress, uint8_t eeaddress );
    public:
        virtual void init();

        virtual int32_t get_traw();
        virtual double get_traw_sc();
        virtual double get_temp_c();
        virtual double get_temp_f();
        virtual double get_temperature_scale_factor();

        virtual int32_t get_praw();
        virtual double get_praw_sc();
        virtual double get_pcomp();
        virtual double get_pressure_scale_factor();
        virtual double get_pressure();
};


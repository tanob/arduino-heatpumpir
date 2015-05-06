/*
*/
#ifndef GreeIR_h
#define GreeIR_h

#include <Arduino.h>
#include <IRSender.h>
#include <HeatpumpIR.h>

// Gree timing constants
#define GREE_HDR_MARK  8755
#define GREE_HDR_SPACE 4239
#define GREE_BIT_MARK     600
#define GREE_ONE_SPACE   1488
#define GREE_ZERO_SPACE   420
#define GREE_MSG_SPACE   19240


// GREE codes
//#define MIDEA_AIRCON1_MODE_AUTO      0x10 // Operating mode
//#define MIDEA_AIRCON1_MODE_HEAT      0x30
//#define MIDEA_AIRCON1_MODE_COOL      0x00
//#define MIDEA_AIRCON1_MODE_DRY       0x20
//#define MIDEA_AIRCON1_MODE_FAN       0x60
//#define MIDEA_AIRCON1_MODE_FP        0x70 // Not a real mode...
//#define MIDEA_AIRCON1_MODE_OFF       0xFE // Power OFF - not real codes, but we need something...
//#define MIDEA_AIRCON1_MODE_ON        0xFF // Power ON
//#define MIDEA_AIRCON1_FAN_AUTO       0x02 // Fan speed
//#define MIDEA_AIRCON1_FAN1           0x06
//#define MIDEA_AIRCON1_FAN2           0x05
//#define MIDEA_AIRCON1_FAN3           0x03


class GreeIR : public HeatpumpIR
{
  public:
    GreeIR();
    void send(IRSender& IR, byte powerModeCmd, byte operatingModeCmd, byte fanSpeedCmd, byte temperatureCmd, byte swingVCmd, byte swingHCmd);

  private:
    void sendGree(IRSender& IR, byte operatingMode, byte fanSpeed, byte temperature);
    void sendGreeRaw(IRSender& IR, byte sendBuffer[]);
};

#endif

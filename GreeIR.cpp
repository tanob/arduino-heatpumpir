#include <Arduino.h>
#include <GreeIR.h>

GreeIR::GreeIR() : HeatpumpIR()
{
  static const prog_char model[] PROGMEM = "gree";
  static const prog_char info[]  PROGMEM = "{\"mdl\":\"gree\",\"dn\":\"Ultimate Pro Plus\",\"mT\":16,\"xT\":30,\"fs\":4,\"maint\":[10]}";

  _model = model;
  _info = info;
}


void GreeIR::send(IRSender& IR, byte powerModeCmd, byte operatingModeCmd, byte fanSpeedCmd, byte temperatureCmd, byte swingVCmd, byte swingHCmd)
{
  sendGree(IR, 0, 0, 0);
}

// Send the Gree code
void GreeIR::sendGree(IRSender& IR, byte operatingMode, byte fanSpeed, byte temperature)
{
  byte sendBuffer[0];

  // Send the code
  sendGreeRaw(IR, sendBuffer);
}

// Send the Gree raw code
void GreeIR::sendGreeRaw(IRSender& IR, byte sendBuffer[])
{
  // 31,05,20,50, 00,20,00,20 = POWER ON...
  byte sendBuffer1[4] = { 0x31,0x05,0x20,0x50 };
  byte sendBuffer2[4] = { 0, 0x20, 0, 0x20 };

  IR.setFrequency(38);

  // Header
  IR.mark(GREE_HDR_MARK);
  IR.space(GREE_HDR_SPACE);

  for (int i=0; i<4; i++) {
    IR.sendIRByte(sendBuffer1[i], GREE_BIT_MARK, GREE_ZERO_SPACE, GREE_ONE_SPACE);
  }

  // Pause
  IR.mark(GREE_BIT_MARK);
  IR.space(GREE_MSG_SPACE);

  for (int i=0; i<4; i++) {
    IR.sendIRByte(sendBuffer2[i], GREE_BIT_MARK, GREE_ZERO_SPACE, GREE_ONE_SPACE);
  }

  // End mark
  IR.mark(GREE_BIT_MARK);
  IR.space(0);
}

/*
 * Copyright (C)2019 Kai Ludwig, DG4KLU
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef _FW_TRX_H_
#define _FW_TRX_H_

#include "fw_sound.h"
#include "fw_i2c.h"
#include "fw_calibration.h"
#include "fw_codeplug.h"

extern const int RADIO_VHF_MIN;
extern const int RADIO_VHF_MAX;
extern const int RADIO_UHF_MIN;
extern const int RADIO_UHF_MAX;

enum RADIO_MODE { RADIO_MODE_NONE,RADIO_MODE_ANALOG,RADIO_MODE_DIGITAL};
enum DMR_ADMIT_CRITERIA { ADMIT_CRITERIA_ALWAYS,ADMIT_CRITERIA_CHANNEL_FREE,ADMIT_CRITERIA_COLOR_CODE};
enum DMR_MODE {DMR_MODE_AUTO,DMR_MODE_ACTIVE,DMR_MODE_PASSIVE,DMR_MODE_SFR};

extern int trxDMRMode;

extern volatile bool trxIsTransmitting;
extern uint32_t trxTalkGroupOrPcId;
extern uint32_t trxDMRID;
extern int trx_measure_count;
extern int txstopdelay;
extern volatile uint8_t trxRxSignal;
extern volatile uint8_t trxRxNoise;
extern volatile bool trxIsTransmittingTone;
extern calibrationPowerValues_t trxPowerSettings;

int trx_carrier_detected(void);
void trx_check_analog_squelch(void);
int	trxGetMode(void);
int	trxGetBandwidthIs25kHz(void);
int	trxGetFrequency(void);
void trxSetModeAndBandwidth(int mode, bool bandwidthIs25kHz);
void trxSetFrequency(int fRx,int fTx, int dmrMode);
void trx_setRX(void);
void trx_setTX(void);
void trx_activateRx(void);
void trx_activateTx(void);
void trxSetPowerFromLevel(int powerLevel);
uint16_t trxGetPower(void);
void trxUpdateC6000Calibration(void);
void trxUpdateAT1846SCalibration(void);
void trxSetDMRColourCode(int colourCode);
int trxGetDMRColourCode(void);
int trxGetDMRTimeSlot(void);
void trxSetDMRTimeSlot(int timeslot);
bool trxCheckFrequencyIsVHF(int frequency);
bool trxCheckFrequencyIsUHF(int frequency);
bool trxCheckFrequency(int tmp_frequency);
void trxSetTxCTCSS(int toneFreqX10);
void trxSetRxCTCSS(int toneFreqX10);
bool trxCheckCTCSSFlag(void);
bool trxCheckFrequencyInAmateurBand(int tmp_frequency);
bool trxCheckFrequencyIsSupportedByTheRadioHardware(int frequency);
void trxReadRSSIAndNoise(void);
void trxSelectVoiceChannel(uint8_t channel);
void trxSetTone1(int toneFreq);
void trxSetTone2(int toneFreq);
void trxSetDTMF(int code);
void trxUpdateTsForCurrentChannelWithSpecifiedContact(struct_codeplugContact_t *contactData);

#endif /* _FW_TRX_H_ */

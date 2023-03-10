#pragma once

#include <stdbool.h>
#include <stdint.h>

#define DUSS_MEDIA_CONTROL_PATH "/dev/dmi_media_control"
#define DUSS_MEDIA_DMI_PLAYBACK_PATH "/dev/dmi_video_playback"

#define DUSS_CLAIM_BRIDGE_IO_PKT 0x800c4205
#define DUSS_RELEASE_BRIDGE_IO_PKT 0x400c4206

typedef unsigned char undefined;
typedef enum media_cmd_id {
  DUSS_MEDIA_CMD_AV_START = 11,
  DUSS_MEDIA_CMD_AV_STOP = 12,
  DUSS_MEDIA_CMD_AVIN_SET_PARAM = 122,
  DUSS_MEDIA_CMD_AVIN_START = 120,
  DUSS_MEDIA_CMD_AVIN_STOP = 121,
  DUSS_MEDIA_CMD_GND_DISP_FOV_ADJ = 110,
  DUSS_MEDIA_CMD_GND_LV_START = 0,
  DUSS_MEDIA_CMD_GND_LV_STO_START = 106,
  DUSS_MEDIA_CMD_GND_LV_STO_STOP = 107,
  DUSS_MEDIA_CMD_GND_LV_STOP = 1,
  DUSS_MEDIA_CMD_GND_LV_TRANS_OUT_START = 108,
  DUSS_MEDIA_CMD_GND_LV_TRANS_OUT_STOP = 109,
  DUSS_MEDIA_CMD_GND_STO_START = 102,
  DUSS_MEDIA_CMD_GND_STO_STOP = 103,
  DUSS_MEDIA_CMD_HDMI_START = 20,
  DUSS_MEDIA_CMD_HDMI_STOP = 21,
  DUSS_MEDIA_CMD_HDMI_VIDEO_CHG = 22,
  DUSS_MEDIA_CMD_PB_FLUSH = 32,
  DUSS_MEDIA_CMD_PB_START = 30,
  DUSS_MEDIA_CMD_PB_STOP = 31,
  DUSS_MEDIA_CMD_SET_ENC_STRATEGY = 41,
  DUSS_MEDIA_CMD_UAV_LV_START = 2,
  DUSS_MEDIA_CMD_UAV_LV_STO_START = 104,
  DUSS_MEDIA_CMD_UAV_LV_STO_STOP = 105,
  DUSS_MEDIA_CMD_UAV_LV_STOP = 3,
  DUSS_MEDIA_CMD_UAV_STO_START = 100,
  DUSS_MEDIA_CMD_UAV_STO_STOP = 101,
  DUSS_MEDIA_CMD_WATERMARK_SET_PARAM = 130,
  DUSS_MEDIA_MAX_CMD_ID = 255,
  DUSS_MEDIA_PB_EOS = 33
} media_cmd_id;

struct duss_media_apcp_cmd {
  int8_t magic[4];
  uint32_t cmd_id;
  uint32_t param1;
  uint32_t param2;
};

typedef struct duss_media_apcp_cmd duss_media_apcp_cmd_t;

struct bridge_io_pkt {
  uint32_t paddr;
  uint32_t size;
  uint32_t notify;
};

typedef struct bridge_io_pkt bridge_io_pkt_t;

struct stream_in_header {
  uint8_t hdr_type;
  uint8_t is_parted;
  uint8_t eof;
  uint8_t eos;
  undefined field4_0x4;
  undefined field5_0x5;
  undefined field6_0x6;
  undefined field7_0x7;
  uint64_t pts;
  uint32_t payload_offset;
  uint32_t payload_lenth;
  bool is_first_frm;
  undefined field12_0x19;
  undefined field13_0x1a;
  undefined field14_0x1b;
  undefined field15_0x1c;
  undefined field16_0x1d;
  undefined field17_0x1e;
  undefined field18_0x1f;
};

typedef struct stream_in_header stream_in_header_t;

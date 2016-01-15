# nxtOSEKルートディレクトリ
ROOT = /Users/e145763/etrobo/nxtOSEK/

TOPPERS_OSEK_ROOT_SG = /Users/e145763/etrobo/nxtOSEK/toppers_osek

# ターゲット
TARGET = robo9re

# インクルードパス
USER_INC_PATH= \
	$(ROOT)/ecrobot/nxtway_gs_balancer \
	app \
	dev \
	run \
	sce \
	sce_R \
	sce_L
# ライブラリ
USER_LIB = nxtway_gs_balancer

# Cソースファイル
TARGET_SOURCES = \
	sce_R/Basic_R.c \
	sce_R/FigureL.c \
	sce_R/RPark.c \
	sce_R/Train.c \
	sce_L/Basic_L.c \
	sce/Stepup.c \
	sce/ColorJudgement.c \
	sce/SearchLine.c \
	run/LineTracer.c \
	run/NolineTracer.c \
	app/PID.c \
	app/SteerControl.c \
	app/RearControl.c \
	dev/GyroSensor.c \
	dev/LightSensor.c \
	dev/SonarSensor.c \
	dev/TouchSensor.c \
	dev/Motor.c \
	StopConditions.c \
	UI.c \
	balancer_param.c \
	Main.c \

# TOPPERS/ATK1(OSEK)設定ファイル
TOPPERS_OSEK_OIL_SOURCE = Main.oil

# 下記のマクロは変更しないでください
O_PATH ?= build

include $(ROOT)/ecrobot/ecrobot.mak

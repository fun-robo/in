# nxtOSEKルートディレクトリ
NXTOSEK_ROOT = ../nxtOSEK

# ターゲット実行形式ファイル名
#TARGET = model_impl
TARGET = maimai

# インクルードパス
USER_INC_PATH= $(NXTOSEK_ROOT)/ecrobot/nxtway_gs_balancer

# ライブラリ
USER_LIB = nxtway_gs_balancer

# Cソースファイル
TARGET_SOURCES = balancer_param.c LineTracer.c  UI.c ColorJudgement.c BalanceRunner.c TouchSensor.c GyroSensor.c LightSensor.c Motor.c model_impl.c GarageIn.c Basic.c SeeSaw.c LineReturn.c SonarSensor.c LookUpGate.c LookUpRunner.c  Maimai.c TailRunner.c 

# TOPPERS/ATK1(OSEK)設定ファイル
TOPPERS_OSEK_OIL_SOURCE = model_impl.oil

# 下記のマクロは変更しないでください
O_PATH ?= build

include $(NXTOSEK_ROOT)/ecrobot/ecrobot.mak

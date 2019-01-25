# Erika Version 3 integration

## Introduction
 OSEK OS 오픈소스 프로젝트인 Erika 3 RTOS를 Infineon의 AURIX용 개발환경인 BIFACES에 통합하는 것을 목표로 한다.


## Necessary Softwares (Not included in this repo)
- Erika3: download from Erika website.
- Bifaces: download from Infineon (needs a registrion)
## Test Environment
- HW: Aurix TC275 ShieldBuddy
- Compiler: HighTec Free Compiler
- Debugger: Pls UDE as a part of free evluation tool bundle

## Design
- iLLD + Erika3
- os.h, ee.mk

## Integration

### Folder Layout
 - config
 - cpu
 - kernel
 - license.txt


### 적용 순서
1. Copy...
    OS SOURCE CODE
    \plugins\com.eu.evidence.ee3_3.0.1.20181217_gh55\ee_files\
1. OS TOOL (RTDruid)
1. Download Erika3
   http://www.erika-enterprise.com/index.php/download/erika-v3-download.html
    ![](./img/gh55.png)
   - unzip it to OsTool
   - Edit OsCfgGen.mk
    > B_RT_DRUID_CMD=java -jar "$(B_RT_DRUID_TOOLS_DIR)/plugins/org.eclipse.equinox.launcher_1.5.0.v20180512-1130.jar"\
-data $(B_RT_DRUID_TEMP_DIR)/workspace -application com.eu.evidence.rtdruid3.oil.ee.core.generator 
1. c:\Tools\BifacesWin64_Erika3\OsTools\RT-Druid\plugins\com.eu.evidence.ee3_3.0.1.20181217_gh55\ee_files\
1. c:\Tools\BifacesWin64_Erika3\OsTools\RT-Druid\plugins\com.eu.evidence.ee3_3.0.1.20181217_gh55\ee_files\pkg\
1. Erika3는 ee_pull.mk를 이용해서 코드를 프로젝트별로 복사한다.
1. OsCfgGen.mk를 변경해야함

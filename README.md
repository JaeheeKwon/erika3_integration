# Erika Version 3 integration

## Introduction
OSEK OS 오픈소스 프로젝트인 Erika 3 RTOS를 Infineon의 AURIX용 개발환경인 BIFACES에 통합하는 것을 목표로 한다.
Infineon에서 배포되는 BIFACES, iLLD 및 Erika3의 변경이 필요없는 환경을 제공한다.


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
### Erika BUild System
OIL파일을 이용하여 생성된 결과물중 MK폴더내에 Makefile이 존재함. ee.mk
ee.mk를 이용하여 전체 Build를 수행함.


iLLD ENABLE
OS.H 수정
ee.mk 수정
ISR Keyword 사용



OsTools를 별도 폴더에 추가하여 개발...
license 수정


### Folder Layout
 - config
 - cpu
 - kernel
 - license.txt

### 포팅
erika는 cygwin을 이용하여 Windows환경을 지원한다.
Ver2에서는 별도의 makefile을 만들어서 cygwin이 없는 환경이 사용된다.

Pull --> Erika3는 필요한 소스코드를 option에 따라서 copy함...

### ToDo
- pull erika code
  --> 생성된 Makefile을 이용해서 os 코드 가져오기..


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

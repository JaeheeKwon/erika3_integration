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

Copy...
OS SOURCE CODE
\plugins\com.eu.evidence.ee3_3.0.1.20181217_gh55\ee_files\
OS TOOL (RTDruid)

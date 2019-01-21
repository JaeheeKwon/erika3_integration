# Erika Version 3 integration

## Introduction
 Just to provide an Erika V3 OSEK OS integration into the Bifaces SW development environment from Infineon.
 The current Bifaces does support Erika V2 and this porject will just follow the same way, i.e. Makefile modfication.

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

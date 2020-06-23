#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Aerolinea.o \
	${OBJECTDIR}/AerolineaData.o \
	${OBJECTDIR}/Avion.o \
	${OBJECTDIR}/AvionData.o \
	${OBJECTDIR}/Ciudad.o \
	${OBJECTDIR}/Cola.o \
	${OBJECTDIR}/Horario.o \
	${OBJECTDIR}/Itinerario.o \
	${OBJECTDIR}/Tiquete.o \
	${OBJECTDIR}/Usuario.o \
	${OBJECTDIR}/VentanaComprarTiquete.o \
	${OBJECTDIR}/VentanaEscogerAerolinea.o \
	${OBJECTDIR}/VentanaFactura.o \
	${OBJECTDIR}/VentanaItinerario.o \
	${OBJECTDIR}/VentanaLoginAdmin.o \
	${OBJECTDIR}/VentanaPrincipal.o \
	${OBJECTDIR}/Vuelo.o \
	${OBJECTDIR}/VueloData.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=`pkg-config gtkmm-3.0 --cflags` -pthread 
CXXFLAGS=`pkg-config gtkmm-3.0 --cflags` -pthread 

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/neotravel

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/neotravel: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/neotravel ${OBJECTFILES} ${LDLIBSOPTIONS} `pkg-config gtkmm-3.0 --libs`

${OBJECTDIR}/Aerolinea.o: Aerolinea.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Aerolinea.o Aerolinea.cpp

${OBJECTDIR}/AerolineaData.o: AerolineaData.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AerolineaData.o AerolineaData.cpp

${OBJECTDIR}/Avion.o: Avion.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Avion.o Avion.cpp

${OBJECTDIR}/AvionData.o: AvionData.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AvionData.o AvionData.cpp

${OBJECTDIR}/Ciudad.o: Ciudad.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Ciudad.o Ciudad.cpp

${OBJECTDIR}/Cola.o: Cola.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cola.o Cola.cpp

${OBJECTDIR}/Horario.o: Horario.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Horario.o Horario.cpp

${OBJECTDIR}/Itinerario.o: Itinerario.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Itinerario.o Itinerario.cpp

${OBJECTDIR}/Tiquete.o: Tiquete.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tiquete.o Tiquete.cpp

${OBJECTDIR}/Usuario.o: Usuario.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Usuario.o Usuario.cpp

${OBJECTDIR}/VentanaComprarTiquete.o: VentanaComprarTiquete.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaComprarTiquete.o VentanaComprarTiquete.cpp

${OBJECTDIR}/VentanaEscogerAerolinea.o: VentanaEscogerAerolinea.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaEscogerAerolinea.o VentanaEscogerAerolinea.cpp

${OBJECTDIR}/VentanaFactura.o: VentanaFactura.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaFactura.o VentanaFactura.cpp

${OBJECTDIR}/VentanaItinerario.o: VentanaItinerario.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaItinerario.o VentanaItinerario.cpp

${OBJECTDIR}/VentanaLoginAdmin.o: VentanaLoginAdmin.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaLoginAdmin.o VentanaLoginAdmin.cpp

${OBJECTDIR}/VentanaPrincipal.o: VentanaPrincipal.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VentanaPrincipal.o VentanaPrincipal.cpp

${OBJECTDIR}/Vuelo.o: Vuelo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Vuelo.o Vuelo.cpp

${OBJECTDIR}/VueloData.o: VueloData.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VueloData.o VueloData.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

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
	${OBJECTDIR}/Case.o \
	${OBJECTDIR}/Case_Entier.o \
	${OBJECTDIR}/Case_Vide.o \
	${OBJECTDIR}/Grille.o \
	${OBJECTDIR}/Grille_2048.o \
	${OBJECTDIR}/Grille_2048_VarN.o \
	${OBJECTDIR}/Grille_2048_VarT.o \
	${OBJECTDIR}/Grille_Taquin.o \
	${OBJECTDIR}/Joueur.o \
	${OBJECTDIR}/JoueurHumain.o \
	${OBJECTDIR}/JoueurRobot.o \
	${OBJECTDIR}/TCase.o \
	${OBJECTDIR}/run.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/project

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/project: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/project ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Case.o: Case.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Case.o Case.cpp

${OBJECTDIR}/Case_Entier.o: Case_Entier.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Case_Entier.o Case_Entier.cpp

${OBJECTDIR}/Case_Vide.o: Case_Vide.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Case_Vide.o Case_Vide.cpp

${OBJECTDIR}/Grille.o: Grille.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Grille.o Grille.cpp

${OBJECTDIR}/Grille_2048.o: Grille_2048.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Grille_2048.o Grille_2048.cpp

${OBJECTDIR}/Grille_2048_VarN.o: Grille_2048_VarN.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Grille_2048_VarN.o Grille_2048_VarN.cpp

${OBJECTDIR}/Grille_2048_VarT.o: Grille_2048_VarT.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Grille_2048_VarT.o Grille_2048_VarT.cpp

${OBJECTDIR}/Grille_Taquin.o: Grille_Taquin.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Grille_Taquin.o Grille_Taquin.cpp

${OBJECTDIR}/Joueur.o: Joueur.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Joueur.o Joueur.cpp

${OBJECTDIR}/JoueurHumain.o: JoueurHumain.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/JoueurHumain.o JoueurHumain.cpp

${OBJECTDIR}/JoueurRobot.o: JoueurRobot.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/JoueurRobot.o JoueurRobot.cpp

${OBJECTDIR}/TCase.o: TCase.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TCase.o TCase.cpp

${OBJECTDIR}/run.o: run.cc
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/run.o run.cc

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

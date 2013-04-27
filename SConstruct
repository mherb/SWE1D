#!/usr/bin/python

# @file
# This file is part of SWE1D
#
# SWE1D is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# SWE1D is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with SWE1D.  If not, see <http://www.gnu.org/licenses/>.
#
# Diese Datei ist Teil von SWE1D.
#
# SWE1D ist Freie Software: Sie koennen es unter den Bedingungen
# der GNU General Public License, wie von der Free Software Foundation,
# Version 3 der Lizenz oder (nach Ihrer Option) jeder spaeteren
# veroeffentlichten Version, weiterverbreiten und/oder modifizieren.
#
# SWE1D wird in der Hoffnung, dass es nuetzlich sein wird, aber
# OHNE JEDE GEWAEHELEISTUNG, bereitgestellt; sogar ohne die implizite
# Gewaehrleistung der MARKTFAEHIGKEIT oder EIGNUNG FUER EINEN BESTIMMTEN
# ZWECK. Siehe die GNU General Public License fuer weitere Details.
#
# Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
# Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
# 
# @copyright 2013 Technische Universitaet Muenchen
# @author Sebastian Rettenberger <rettenbs@in.tum.de>

print '******************************************'
print '** Welcome to the build script of SWE1D **'
print '******************************************'
print 'SWE1D Copyright (C) 2013'
print ''
print '  Technische Universitaet Muenchen'
print '  Department of Informatics'
print '  Chair of Scientific Computing'
print ''
print 'SWE1D comes with ABSOLUTELY NO WARRANTY.'
print 'SWE1D is free software, and you are welcome to redistribute it'
print 'under certain conditions.'
print 'Details can be found in the file \'gpl.txt\'.'
print ''

import os

# Scons environement
env = Environment(tools=['default','cxxtest'])

# eclipse specific flag
env.Append(CCFLAGS=['-fmessage-length=0'])

# Pass optimize=<level> to set optimization level
# by default level 0 (no optimzation) is used
if ARGUMENTS.get('optimize', 0):
    env.Append(CCFLAGS=['-O' + ARGUMENTS.get('optimize', '0')])

# Pass debug=1 for a debug build
if ARGUMENTS.get('debug', 0):
    env.Append(CCFLAGS=['-g'])

# Pass compiler=<name> to use <name> as compiler instead of g++
if ARGUMENTS.get('compiler', 0):
    env['CXX'] = ARGUMENTS.get('compiler')

# Add source directory to include path (important for subdirectories)
env.Append(CPPPATH=['.','#src'])

# Output directory
buildDir = '#build'
srcDir = '#src'
testsDir = '#tests'

# Generate the program name
programName = 'SWE1D'
testName = programName+'test'

# Get the source code files
Export('env')
env.srcFiles = []
SConscript(os.path.join('src', 'SConscript'),
    variant_dir=os.path.join(buildDir, 'build_'+programName),
    duplicate=0)
Import('env')

# Build the program
program = env.Program(os.path.join(buildDir, programName), env.srcFiles)

# Build unit tests
# TODO: implement this in a cleaner way, maybe move to SConscript file?
env['CXXTEST_SKIP_ERRORS'] = True
testsFiles = [
    os.path.join(testsDir, 'WavePropagationTest.h'),
    env.Object(os.path.join(srcDir,'WavePropagation.cpp'))
]
tests = env.CxxTest(os.path.join(buildDir, testName), testsFiles)

Default(program)
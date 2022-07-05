########################################################################
#
# File Name: SConstruct
#
# Objective: This is the scons based build file for a ray tracer
#
# Revision History:
#
# Login          MM/DD/YYYY      Description
#
# rlange         03/01/2010      Initial Draft
# rlange         03/04/2010      Aded RayTracer to build
# rlange         03/09/2010      Aded Color to the build
#
###########################################################################

SOURCE_DIR = './src/'
list_of_src_files_to_compile = ['Main.cc',
                                'Object.cc',
                                'Ray.cc', 
                                'Sphere.cc',
                                'RayTracer.cc',
                                'Color.cc',
                                'Plane.cc',
                                'Triangle.cc',
                                'Maths.cpp',
                                'Torus.cc',
                                'CheckerWall.cc']

list_of_src_files_with_path = []

for file in list_of_src_files_to_compile:
    list_of_src_files_with_path += [SOURCE_DIR + file]

env = Environment(CPPPATH = ['#/include'])

env.Program(target='RayTracer',
            source= list_of_src_files_with_path,
            CCFLAGS = '-O2 -W -Wall -Wextra -Werror -Wno-unused-parameter')

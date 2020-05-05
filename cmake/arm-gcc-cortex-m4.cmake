set(MCPU_FLAGS "-mthumb -mcpu=cortex-m4")
set(VFP_FLAGS "-mfloat-abi=hard -mfpu=fpv4-sp-d16")
set(LD_FLAGS "")
set(SPECS_FLAGS "--specs=nano.specs")

include(${CMAKE_CURRENT_LIST_DIR}/arm-gcc-toolchain.cmake)
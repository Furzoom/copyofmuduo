set(base_SRCS
  UtcTime.cc
  )

add_library(deiio_base ${base_SRCS})

add_subdirectory(tests)

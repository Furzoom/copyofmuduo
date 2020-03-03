set(base_SRCS
  Thread.cc
  UtcTime.cc
  )

add_library(deiio_base ${base_SRCS})

add_subdirectory(tests)


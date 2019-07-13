load('//:buckaroo_macros.bzl', 'buckaroo_deps')

cxx_library(
  name = 'niftyfs',
  header_namespace = 'niftyfs',
  exported_headers = subdir_glob([
    ('include', '**/*.hpp'),
    ('include', '**/*.h'),
  ]),
  headers = subdir_glob([
    ('private_include', '**/*.hpp'),
    ('private_include', '**/*.h'),
  ]),
  srcs = glob([
    'src/**/*.cpp',
  ]),
  deps = buckaroo_deps(),
  visibility = [
    'PUBLIC',
  ],
)

cxx_binary(
  name = 'app',
  srcs = [
    'src/main.cpp',
  ],
  deps = [
    '//:niftyfs',
  ],
)

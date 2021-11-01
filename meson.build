project(
  'looping-lex',
  'cpp', 'c',
  license: 'MIT',
  version: '1.0.0',
  default_options: ['cpp_std=c++20'],
)

flex = find_program('flex', required: true)

lgen = generator(flex,
output : '@PLAINNAME@.yy.c',
arguments : ['-o', '@OUTPUT@', '@INPUT@'])

lexfiles = lgen.process('flex/lex.l')


openmp = dependency('openmp')
incdir = include_directories('include')

sources = ['src/Lexer.cc', 'src/Tokenizer.cc']


executable(
  'looping-lex',
  sources,
  'src/LoopingLex.cc',
  include_directories : incdir,
  dependencies: openmp
)

executable(
  'flex-lex',
  lexfiles
)


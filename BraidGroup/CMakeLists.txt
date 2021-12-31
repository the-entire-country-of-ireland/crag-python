cmake_minimum_required(VERSION 3.8)

include("../cmake/common.cmake")

crag_library(BraidGroup
  braid_group
  ThRightNormalForm
  ThRightNormalForm_uss
  ThRightNormalForm_sss
  LinkedBraidStructure
  DehornoyForm
  ShortBraidForm
  ThLeftNormalForm
  colored_burau
  stochastic_rewrite
)

target_link_libraries(BraidGroup
  PUBLIC Boost::boost
  PUBLIC crag_general
  PUBLIC Elt
  PUBLIC FiniteField
  PUBLIC Polynomial
  PUBLIC Matrix
  PUBLIC Random
)

crag_main(test_rightNF BraidGroup)
crag_main(test_leftNF BraidGroup)
crag_main(test_deh_form BraidGroup)
crag_main(ireland BraidGroup)

crag_main_python(fast_braids BraidGroup)



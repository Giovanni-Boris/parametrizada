add_test( Stack.StackEMpty /home/boris/Escritorio/parametrizada/build/stack_array [==[--gtest_filter=Stack.StackEMpty]==] --gtest_also_run_disabled_tests)
set_tests_properties( Stack.StackEMpty PROPERTIES WORKING_DIRECTORY /home/boris/Escritorio/parametrizada/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( stack_array_TESTS Stack.StackEMpty)

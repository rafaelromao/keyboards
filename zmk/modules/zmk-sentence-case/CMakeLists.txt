if ((NOT CONFIG_ZMK_SPLIT) OR CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
  target_include_directories(app PRIVATE include)
  target_sources_ifdef(CONFIG_ZMK_BEHAVIOR_SENTENCE_CASE app PRIVATE
    src/behavior_sentence_case.c
    src/behavior_sentence_morph.c)
endif()

if(CONFIG_ZMK_CORNEISH_ZEN_CENTRAL_LOGO)
  zephyr_library()
  zephyr_library_sources(src/central_logo.c)
  zephyr_library_sources(
    ${APPLICATION_SOURCE_DIR}/boards/lowprokb/corneish_zen/widgets/icons/zenlogo.c
  )
  zephyr_library_include_directories(${ZEPHYR_LVGL_MODULE_DIR})

  # Decorate the stock screen as it is loaded, without replacing its widgets or
  # modifying ZMK's board sources. lv_scr_load() is an alias for lv_screen_load().
  zephyr_link_libraries(-Wl,--wrap=lv_screen_load)
endif()

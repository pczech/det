<?php

/**
 * @file
 * Artwork entity management pages' callbacks.
 */

/**
 * Overview types page callback.
 */
function artwork_pcb_overview_types() {
  det_trace_funct();

  foreach (_artwork_types() as $type => $info) {
    $type_url = str_replace('_', '-', $type);
    $label = t('View @type', array('@type' => $info->name));
    $items[] = l($label, 'admin/structure/artworks/manage/' . $type_url);
  }

  return theme('item_list', array('items' => $items));
}


/**
 * Manage types page callback.
 */
function artwork_pcb_manage_types($artwork_type) {
  det_trace_funct();

  return $artwork_type->name . ': ' . $artwork_type->description;
}


/**
 * Add page callback.
 */
function artwork_pcb_add_page() {
  det_trace_funct();

  $item = menu_get_item();
  $links = system_admin_menu_block($item);
  // dpm($item);
  // dpm($links);

  foreach($links as $link) {
    $items[] = l($link['title'], $link['href'], $item['localized_options'])
      . ': ' . filter_xss_admin($link['description']);
  }

  // dpm($items);
  return theme('item_list', array('items' => $items));
}


/**
 * Add artwork callback.
 */
function artwork_pcb_add($type) {
  det_trace_funct();

  $type = isset($type) ? str_replace('-', '_', $type) : NULL;
  $types = _artwork_types();
  if (empty($types[$type])) {
    return MENU_NOT_FOUND;
  }

  dpm(entity_get_controller('artwork'));

  return t('Add artwork');
}

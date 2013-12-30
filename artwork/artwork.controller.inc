<?php

/**
 * @file
 * Artwork entity controller class.
 */

/**
 * Controller class for artworks.
 *
 * Extends the DrupalDefaultEntityController class.
 */
class ArtworkController extends DrupalDefaultEntityController {
  /**
   * Create the artwork entity object.
   */
  function create($type = '') {
    return (object) array(
      'aid' => '',
      'type' => $type,
      'title' => '',
      );
  }

  /**
   * Save the artwork entity object.
   */
  function save($artwork) {
    det_trace_funct();
    // TODO
  }
}

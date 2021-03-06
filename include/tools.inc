<?php

/**
 * @file
 * Common tools for DET modules.
 */


/**
 * Traces function calls.
 */
function det_trace_funct() {
  $trace = debug_backtrace();
  if (isset($trace[1])) {
    dpm($trace[1]['function']);
  }
}
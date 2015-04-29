<?php

/**
 * Process variables for ting-extrasearch-results.tpl.php.
 */
function template_preprocess_ting_extrasearch_results(&$variables) {
  $variables['search_results'] = '';
  if (!empty($variables['module'])) {
    $variables['module'] = check_plain($variables['module']);
  }

  foreach ($variables['results'] as $result) {
    $variables['search_results'] .= theme('search_result', array('result' => $result, 'module' => $variables['module']));
  }
  $variables['pager'] = theme('ting_extrasearch_pager', array('tags' => NULL));
}


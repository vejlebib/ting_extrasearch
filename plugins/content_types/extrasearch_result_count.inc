<?php
/**
 * @file
 * Panels pane to display page title with result count.
 */

$plugin = array(
  'title' => t('Ting extrasearch - page title'),
  'description' => t("Display title with result count."),
  'content_types' => array('ting_extrasearch'),
  'render callback' => 'ting_extrasearch_result_count_content_type_render',
  'category' => t('Ting'),
  'required context' => new ctools_context_required(t('Keywords'), 'string'),
  'render last' => TRUE,
);

/**
 * Render the ting extrasearch results amount block.
 */
function ting_extrasearch_result_count_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $search_result = drupal_static('ting_extrasearch_results');
  if (isset($search_result)) {
    $results = isset($search_result->numTotalObjects) ? (int) $search_result->numTotalObjects : 0;
    $block->content = array(
      '#prefix' => '<h1 class="page-title">',
      '#suffix' => '</h1>',
      '#markup' => format_plural($results > 1 ? $results : 1,
        'Search result <span class="search-field-in-content--amount">(' . $results . ' result)</span>',
        'Search result <span class="search-field-in-content--amount">(!count results)</span>', array(
          '!count' => $results,
        )
      ),
    );
  }

  return $block;
}

/**
 * Enable admin settings page.
 */
function ting_extrasearch_search_result_count_content_type_edit_form($form, &$form_state) {
  return $form;
}

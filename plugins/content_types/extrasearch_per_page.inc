<?php
/**
 * @file
 * Panels pane to display "number of results per page" selector.
 */

$plugin = array(
  'title' => t('Ting extrasearch - results per page'),
  'description' => t("Display results per page selector."),
  'content_types' => array('ting_extrasearch'),
  'edit form' => 'ting_extrasearch_search_per_page_content_type_edit_form',
  'render callback' => 'ting_extrasearch_per_page_content_type_render',
  'category' => t('Ting'),
  'required context' => new ctools_context_required(t('Keywords'), 'string'),
  'defaults' => array(
    'select_type' => array('dropdown'),
  ),
  'render last' => TRUE,
);

/**
 * Render the ting extrasearch results amount block.
 */
function ting_extrasearch_per_page_content_type_render($subtype, $conf, $panel_args, $context) {
  $sizes = extrarecords_per_page_controls_content();

  $content = '';
  if (!empty($sizes) && isset($conf['select_type'])) {
    switch ($conf['select_type']) {
      case 'list':
        $items = array();
        foreach ($sizes as $size) {
          $items[] = array(
            'data' => l($size['text'], $_GET['q'], array(
              'query' => $size['query'],
              'attributes' => array(
                'class' => ($size['selected'] == TRUE ? array('selected') : array('')),
              ),
            )),
          );
        }

        $content = array(
          '#theme' => 'item_list',
          '#title' => t('Results on page:'),
          '#attributes' => array(
            'class' => array('ting-extrasearch-records-per-page'),
          ),
          '#items' => $items,
        );
        break;

      case 'dropdown':
        $content = drupal_get_form('ting_extrasearch_per_page_form', $sizes);
        break;
    }
  }

  // Create the output.
  $block = new stdClass();
  $block->content = $content;

  return $block;
}

/**
 * Implements hook_form().
 *
 * Creates the select "number of results per page" form.
 */
function ting_extrasearch_per_page_form($form, &$form_state, $sizes) {
  $form = array(
    '#attributes' => array(
      'class' => array('search-field-in-content--sort-wrapper'),
    ),
    '#attached' => array(
      'js' => array(
        // Script to handle usability in the frontend (clicks).
        drupal_get_path('module', 'ting_extrasearch') . '/js/ting_extrasearch_per_page.js',
      ),
    ),
  );

  $options = array();
  $default = array();
  foreach ($sizes as $size) {
    $options[$size['text']] = t('Number of search result per page: !num', array('!num' => $size['text']));

    if ($size['selected'] == TRUE) {
      $default = array($size['text']);
    }
  }

  $form['size'] = array(
    '#type' => 'select',
    '#required' => FALSE,
    '#options' => $options,
    '#default_value' => $default,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Size'),
    '#states' => array(
      'visible' => array(':input[name="op"]' => array('value' => '')),
    ),
  );

  return $form;
}

/**
 * Process submitted data for records per page form.
 */
function ting_extrasearch_per_page_form_submit($form, &$form_state) {
  $query = drupal_get_query_parameters();

  if (isset($form_state['input']['size'])) {
    $query = array('size' => $form_state['input']['size']) + $query;
  }

  $form_state['redirect'] = array($_GET['q'], array('query' => $query));
}

/**
 * Enable admin settings page.
 */
function ting_extrasearch_search_per_page_content_type_edit_form($form, &$form_state) {
  $form['select_type'] = array(
    '#type' => 'select',
    '#title' => 'Output type',
    '#options' => array(
      'list' => 'HTML list',
      'dropdown' => 'Dropdown',
    ),
    '#default_value' => $form_state['conf']['select_type'],
  );

  return $form;
}

/**
 * Submit handler for search form.
 */
function ting_extrasearch_search_per_page_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

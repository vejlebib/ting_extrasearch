<?php
// $Id: extrasearch-results.tpl.php,v 1.7 2010/08/18 18:40:50 dries Exp $

/**
 * @file
 * Default theme implementation for displaying ting extra search results.
 *
 * We need a custom template because we need a special pager.
 *
 * @see template_preprocess_ting_extrasearch_results()
 */
?>
<?php if ($search_results) : ?>
  <div class="search-results">
    <h2><?php print t('extra Search results');?></h2>
    <ol class="search-results <?php print $module; ?>-results">
      <?php print $search_results; ?>
    </ol>
    <?php print $pager; ?>
  </div>
<?php else : ?>
  <div class="search-results">
    <h2><?php print t('Your extra search yielded no results');?></h2>
    <?php print search_help('search#noresults', drupal_help_arg()); ?>
  </div>
<?php endif; ?>

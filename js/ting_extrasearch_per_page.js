(function($) {
  "use strict";

  $(document).ready(function() {
    $('.pane-extrasearch-per-page select').change(function() {
      // Display search overlay.
      Drupal.TingSearchOverlay();

      // Reloads the page when new size is selected in the drop-down.
      $('#ting-extrasearch-per-page-form').trigger("submit");
    });

    $('.pane-ting-extrasearch-sort-form select').change(function() {
      // Display search overlay.
      Drupal.TingSearchOverlay();
    });
 });
}(jQuery));

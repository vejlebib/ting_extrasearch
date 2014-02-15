(function($) {
  "use strict";

  $(document).ready(function() {
    // Click the label link when a radio button is clicked.
    $('#ting-extrasearch-backend-engines-form input[type="radio"]').change(function() {
      var link = $(this).parent().find('a');
      Drupal.TingSearchOverlay();
      window.location = link.attr('href');
    });

    // When a label link is click, also check the radio button.
    $('#ting-extrasearch-backend-engines-form a').click(function(event) {
      var radio = $(this).parent().parent().find('input[type="radio"]');
      if (radio.is(':checked')) {
        // If it is already checked do nothing.
        event.preventDefault();
        return false;
      }
      else {
        // Check the radio button and continue handling the click event.
        radio.attr('checked', 'checked');
        Drupal.TingSearchOverlay();
        return true;
      }
    });
  });
}(jQuery));

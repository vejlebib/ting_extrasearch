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

    // Moves the search form into the search result page.
    if (window.location.href.indexOf("search/tingextra") > -1) {
      var search = $('.search-field-wrapper');
      search.addClass('search-field-in-content');
      search.addClass('js-search-field-in-content');

      // Remove label.
      search.find('label').remove();

      // Add the search field.
      var element = $('.pane-extrasearch-result-count');
      if (element.length) {
        search.insertAfter('.pane-extrasearch-result-count');
      }
      else {
        search.insertBefore('.view-node-extrasearch-result .search-results');
      }

      // Ensure that the spinner and other stuff works by wrapping it in a
      // search div.
      search.wrap('<div class="search"></div>');

      // Remove tabs (panels visibility rules do not work!).
      $('.pane-page-tabs').remove();

      // Hide top menu bar link.
      $('.topbar-link-search').hide();
    }

  });
}(jQuery));

Description
-----------
The module provides an extra ting search pane. The search can be configured against a different search profile,
that typically will contain an unique selection of Well sources separate from the main TING searches.

The module was created the project "Kulturarv" for experimenting with searches against local and archival library 
sources.  

Dependencies
------------

Same dependencies as ting_search module: search and ting modules.

Installation
------------

Download and enable the module on an existing Ding2 installation. 


Configuration of the module
---------------------------

Go to Admin -> Settings -> Ting -> Ting (admin/config/ting/settings) and set the field 
"Search profile (EXTRA - for additional search pane)"

TO DO
-----

In the current state, this module is only a proof of concept. At the bare minimum it should be modified to
provide an arbitrary number of extra search panes.

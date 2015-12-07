<?php
/**
 * @file
 * ding_event.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function ding_event_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'ding_events_library';
  $page->task = 'page';
  $page->admin_title = 'Library events page';
  $page->admin_description = '';
  $page->path = 'node/%node/events/!tid';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'access content',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Library node',
      'name' => 'entity_id:node',
      'settings' => array(),
      'keyword' => 'node',
    ),
    'tid' => array(
      'id' => 1,
      'identifier' => 'Category term',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'term',
        'vids' => array(
          1 => '1',
          2 => 0,
        ),
        'breadcrumb' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_ding_events_library_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'ding_events_library';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Library events',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'OG group from library node',
        'keyword' => 'group',
        'name' => 'og_group_from_node',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'ding_library' => 'ding_library',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'og_is_node_group',
          'settings' => NULL,
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_breadcrumbs_state' => 1,
    'panels_breadcrumbs_titles' => 'Libraries
%node:title
Events
%tid:name',
    'panels_breadcrumbs_paths' => 'libraries
node/%node:nid
node/%node:nid/events
<none>',
  );
  $display = new panels_display();
  $display->layout = 'threecol_25_50_25_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'top' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '2fc6433a-211b-4cfd-b1ad-eec175a9ba84';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d3218620-6a5f-4b64-bcc6-c6abc27d8d52';
    $pane->panel = 'left';
    $pane->type = 'category_menu';
    $pane->subtype = 'category_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'events',
      'context' => array(
        0 => 'argument_term_1',
        1 => 'argument_entity_id:node_1',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $pane->uuid = 'd3218620-6a5f-4b64-bcc6-c6abc27d8d52';
    $display->content['new-d3218620-6a5f-4b64-bcc6-c6abc27d8d52'] = $pane;
    $display->panels['left'][0] = 'new-d3218620-6a5f-4b64-bcc6-c6abc27d8d52';
    $pane = new stdClass();
    $pane->pid = 'new-60e0d466-f580-47d0-924b-5bad221cd34a';
    $pane->panel = 'middle';
    $pane->type = 'menu_title';
    $pane->subtype = 'menu_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $pane->uuid = '60e0d466-f580-47d0-924b-5bad221cd34a';
    $display->content['new-60e0d466-f580-47d0-924b-5bad221cd34a'] = $pane;
    $display->panels['middle'][0] = 'new-60e0d466-f580-47d0-924b-5bad221cd34a';
    $pane = new stdClass();
    $pane->pid = 'new-9d95dae4-d884-481e-a948-cf0f32e1f081';
    $pane->panel = 'middle';
    $pane->type = 'library_list';
    $pane->subtype = 'library_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'events',
      'context' => array(
        0 => 'argument_term_1',
        1 => 'argument_entity_id:node_1',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = '';
    $pane->uuid = '9d95dae4-d884-481e-a948-cf0f32e1f081';
    $display->content['new-9d95dae4-d884-481e-a948-cf0f32e1f081'] = $pane;
    $display->panels['middle'][1] = 'new-9d95dae4-d884-481e-a948-cf0f32e1f081';
    $pane = new stdClass();
    $pane->pid = 'new-833b735e-0171-40c6-99df-1c7a1c83beb8';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ding_event-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
        1 => 'argument_term_1',
      ),
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array(
      'method' => 'rules',
      'settings' => array(
        'granularity' => 'context',
        'language' => 1,
        'cache_key' => 'panel_context:page-ding_events_library:page_ding_events_library_panel_context',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = '';
    $pane->uuid = '833b735e-0171-40c6-99df-1c7a1c83beb8';
    $display->content['new-833b735e-0171-40c6-99df-1c7a1c83beb8'] = $pane;
    $display->panels['middle'][2] = 'new-833b735e-0171-40c6-99df-1c7a1c83beb8';
    $pane = new stdClass();
    $pane->pid = 'new-da4574d3-255e-4bb6-ab60-67434a5c4e08';
    $pane->panel = 'right';
    $pane->type = 'campaign';
    $pane->subtype = 'campaign';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'ding_campaign_count' => 3,
      'ding_campaign_offset' => 0,
      'context' => array(
        0 => 'empty',
        1 => 'argument_entity_id:node_1',
        2 => 'empty',
        3 => 'empty',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array(
      'method' => 'simple',
      'settings' => array(
        'lifetime' => '1200',
        'granularity' => 'args',
      ),
    );
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = '';
    $pane->uuid = 'da4574d3-255e-4bb6-ab60-67434a5c4e08';
    $display->content['new-da4574d3-255e-4bb6-ab60-67434a5c4e08'] = $pane;
    $display->panels['right'][0] = 'new-da4574d3-255e-4bb6-ab60-67434a5c4e08';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['ding_events_library'] = $page;

  return $pages;

}

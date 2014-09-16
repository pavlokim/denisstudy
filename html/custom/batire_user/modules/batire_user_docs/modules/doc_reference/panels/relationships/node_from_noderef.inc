<?php
/**
 * @file
 * Implements the document reference relationship for Panels.
 */

/**
 * Implementation of hook_ctools_relationships().
 */
function doc_reference_node_from_noderef_ctools_relationships() {
  return array(
    'title' => t('Doc from reference'),
    'keyword' => 'doc_reference',
    'description' => t('Adds a node from a doc reference in a node context; if multiple nodes are referenced, this will get the first referenced node only.'),
    'required context' => new ctools_context_required(t('Node'), 'node'),
    'context' => 'doc_reference_node_from_noderef_context',
    'settings form' => 'doc_reference_node_from_noderef_settings_form',
    'settings form validate' => 'doc_reference_node_from_noderef_settings_form_validate',
  );
}

/**
 * Return a new ctools context based on an existing context.
 */
function doc_reference_node_from_noderef_context($context, $conf) {
  $field = content_fields($conf['field_name']);

  // If unset it wants a generic, unfilled context, which is just NULL.
  if (empty($context->data)) {
    $new_context = ctools_context_create_empty('node', NULL);
  }
  elseif (isset($context->data->{$conf['field_name']}[0]['nid']) && ($nid = $context->data->{$conf['field_name']}[0]['nid'])) {
    if ($node = node_load($nid)) {
      $new_context = ctools_context_create('node', $node);
    }
  }

  if (!empty($new_context)) {
    // Have doc_reference relationships limit CCK field availability as well.
    $restrictions = array_keys(array_filter($field['referenceable_types']));
    if ($restrictions) {
      if (isset($new_context->restrictions['type'])) {
        $new_context->restrictions['type'] = array_unique(array_merge($new_context->restrictions['type'], $restrictions));
      }
      else {
        $new_context->restrictions['type'] = $restrictions;
      }
    }

    return $new_context;
  }
}

/**
 * Settings form for the ctools relationship.
 */
function doc_reference_node_from_noderef_settings_form($conf) {
  $options = array();
  foreach (content_fields() as $field) {
    if ($field['type'] == 'doc_reference') {
      $options[$field['field_name']] = t($field['widget']['label']);
    }
  }
  $form['field_name'] = array(
    '#title' => t('Doc reference field'),
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => isset($conf['field_name']) ? $conf['field_name'] : '',
    '#prefix' => '<div class="clear-block">',
    '#suffix' => '</div>',
  );

  return $form;
}

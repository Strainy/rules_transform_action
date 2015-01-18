<?php
/**
 * @file
 * Rules module integration.
 */

/**
 * Implements hook_rules_action_info().
 */
function rules_action_string_replace_rules_action_info() {
    $items['replace_string'] = array(
        'label' => t('String Replacement'),
        'base' => 'rules_action_string_replace_replace',
        'group' => t('Data'),
        'parameter' => array(
            'method' => array(
                'type' => 'text',
                'label' => 'Search Method',
                'description' => 'The search method (Regular Expression or basic String).',
                'options list' => 'rules_action_string_replace_options_method',
                'optional' => TRUE,
            ),
            'search' => array(
                'type' => 'text',
                'label' => 'Search Value',
                'description' => 'The value being searched for.'
            ),
            'replace' => array(
                'type' => 'text',
                'label' => 'Replace Value',
                'description' => 'Value to replace search value with.',
                'optional' => TRUE,
            ),
            'subject' => array(
                'type' => 'text',
                'label' => 'Subject Value',
                'description' => "Value to search within.",
                'optional' => TRUE,
            ),
        ),
        'provides' => array(
            'replacement_value' => array(
                'type' => 'text',
                'label' => t('New Replaced Value'),
            ),
        ),
    );

    return $items;
}

/**
 * Callback for method listing
 */
function rules_action_string_replace_options_method(){

    return array('regex' => 'Regular Expression', 'str' => 'Simple String',);

}

/**
 * Callback for 'replace' rules action.
 */
function rules_action_string_replace_replace($method, $search, $replace, $subject) {

    if($method == 'regex'){

        //Evaluate with Regular Expression (preg_replace)
        $result = preg_replace($search, $replace, $subject);

    }
    else{

        //Evaluate with simple string replacement function
        $result = str_replace($search, $replace, $subject);

    }

    return array('replacement_value' => $result);

}

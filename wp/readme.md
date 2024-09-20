# Word Press
## How to enable contributor role to edit pages
Update the functions.php under **wp-content/themes/twentytwentyfour**
```
function add_contributor_capabilities() {
    $role = get_role('contributor');
    $role->add_cap('edit_pages');
    $role->add_cap('edit_published_pages');
}
add_action('admin_init', 'add_contributor_capabilities');
```
- or can use **User Role Editor** plugin

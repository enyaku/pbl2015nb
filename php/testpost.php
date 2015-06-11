
<?php

if (!empty($_POST))
{
    // Array of post values for each different form on your page.
    $postNameArr = array('F1_Submit', 'F2_Submit', 'F3_Submit');        

    // Find all of the post identifiers within $_POST
    $postIdentifierArr = array();
        
    foreach ($postNameArr as $postName)
    {
        if (array_key_exists($postName, $_POST))
        {
             $postIdentifierArr[] = $postName;
        }
    }

    // Only one form should be submitted at a time so we should have one
    // post identifier.  The die statements here are pretty harsh you may consider
    // a warning rather than this. 
    if (count($postIdentifierArr) != 1)
    {
        count($postIdentifierArr) < 1 or
            die("\$_POST contained more than one post identifier: " .
               implode(" ", $postIdentifierArr));

        // We have not died yet so we must have less than one.
        die("\$_POST did not contain a known post identifier.");
    }
         
    switch ($postIdentifierArr[0])
    {
    case 'F1_Submit':
       echo "Perform actual code for F1_Submit.";
       break;

    case 'Modify':
       echo "Perform actual code for F2_Submit.";
       break;
           
    case 'Delete':
       echo "Perform actual code for F3_Submit.";
       break;
    }
}
else // $_POST is empty.
{
    echo "Perform code for page without POST data. ";
}
?>


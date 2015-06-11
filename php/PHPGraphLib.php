
<?php
//setup graph
$graph = new stdclass;
$graph->width = 500;
$graph->height = 350;
$graph->data=array('AL'=>3731, 'MI'=>763, 'NY'=>3245, 'TX'=>4373, 'WA'=>12124, 'WY'=>5535);
$graph->setGradient = array('red', 'maroon');
$graph->setLegend = 'true';
$graph->setLegendTitle = 'Widgets';
$graph->setTitle = 'Widgets Produced Per State';
$graph->setTitleLocation = 'left';
  
//JSON encode graph object
$encoded = urlencode(json_encode($graph));
  
//retrieve XML
$target = 'http://www.ebrueggeman.com/phpgraphlib/api/?g=' . $encoded . '&type=xml';
$xml_object =  new SimpleXMLElement($target, NULL, TRUE);
  
//if there are no errors, display graph
if (empty($xml_object->error)) {
  echo $xml_object->imageTag;
}
else {
  echo 'There was an error generating the graph: '. $xml_object->error;
}
?>


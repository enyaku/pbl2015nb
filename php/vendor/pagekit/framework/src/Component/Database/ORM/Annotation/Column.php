<?php

namespace Pagekit\Component\Database\ORM\Annotation;

/**
 * @Annotation
 * @Target("PROPERTY")
 */
final class Column implements Annotation
{
    /** @var string */
    public $name;

    /** @var mixed */
    public $type = 'string';
}

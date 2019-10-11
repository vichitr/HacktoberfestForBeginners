<?php
/**
 * Created by PhpStorm.
 * User: MohammadReza Shaghouzi
 * Date: 10/11/2019
 * Time: 10:51 PM
 */

class stack
{

    public function __construct()
    {
        $this->stack = [];
    }

    public function pull()
    {
        return array_pop($this->stack);
    }

    public function push($obg)
    {
        $this->stack[] = $obg;
    }

    public function top()
    {

        return $this->stack[count($this->stack) - 1];
    }
}

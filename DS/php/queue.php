<?php
/**
 * Created by PhpStorm.
 * User: MohammadReza Shaghouzi
 * Date: 10/11/2019
 * Time: 10:51 PM
 */

class queue
{

    public function __construct()
    {
        $this->queue = [];
    }

    public function dequeue()
    {
        $out=False;
        if (count($this->queue) > 0){
            $out=$this->queue[0];
            unset($this->queue[0]);
            $this->queue=array_values($this->queue);
        }
        return $out;
    }

    public function enqueue($obg)
    {
        $this->queue[] = $obg;
    }

    public function rear()
    {
        $out=False;
        if (count($this->queue) > 0){
            $out=$this->queue[count($this->queue) - 1];
        }
        return $out;
    }
    public function front()
    {
        $out=False;
        if (count($this->queue) > 0){
            $out=$this->queue[0];
        }
        return $out;
    }
}
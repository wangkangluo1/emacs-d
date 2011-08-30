/*
 * =====================================================================================
 *
 *       Filename:  xml.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/07/2011 11:47:54 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kangle.wang (mn), wangkangluo1@gmail.com
 *        Company:  APE-TECH
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

int main (int argc, char **argv)
{
  xmlDocPtr pdoc = NULL;
  xmlNodePtr proot_node = NULL,pnode = NULL,pnode1 = NULL;

  // 创建一个新文档并设置 root 节点
  // 一个 XML 文件只有一个 root 节点
  pdoc = xmlNewDoc (BAD_CAST "1.0");
  proot_node = xmlNewNode (NULL, BAD_CAST "根节点");
  xmlNewProp (proot_node, BAD_CAST "版本", BAD_CAST "1.0");
  xmlDocSetRootElement (pdoc, proot_node);

  pnode = xmlNewNode (NULL, BAD_CAST "子节点1");
  // 创建上面 pnode 的子节点
  xmlNewChild (pnode, NULL, BAD_CAST "子子节点1", BAD_CAST "信息");
  // 添加子节点到 root 节点
  xmlAddChild (proot_node, pnode);

  pnode1 = xmlNewNode (NULL, BAD_CAST "子子节点1");
  xmlAddChild (pnode, pnode1);
  xmlAddChild (pnode1,xmlNewText (BAD_CAST "这是更低的节点,子子子节点1"));

  // 还可以这样直接创建一个子节点到 root 节点上
  xmlNewTextChild (proot_node, NULL, BAD_CAST "子节点2", BAD_CAST "子节点2的内容");
  xmlNewTextChild (proot_node, NULL, BAD_CAST "子节点3", BAD_CAST "子节点3的内容");

  // 保存 xml 为文件,如果没有给出文件名参数，就输出到标准输出
  xmlSaveFormatFileEnc (argc > 1 ? argv[1]:"-", pdoc, "UTF-8", 1);

  // 释放资源
  xmlFreeDoc (pdoc);
  xmlCleanupParser ();
  xmlMemoryDump ();
  return 0;
}

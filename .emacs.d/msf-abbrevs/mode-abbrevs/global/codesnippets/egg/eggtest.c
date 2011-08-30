
 #include <egg2/Egg2.h>
   #include <scholar/ImLexAnalyzer.h>
   #include <scholar/ImTokenList.h>
   #include <scholar/ImCnLexAnalyzer.h>
   #include <scholar/ImCwsLexAnalyzer.h>
   int main()
{
   //ImLexAnalyzer* p_la = (ImLexAnalyzer*)ImCnLexAnalyzer_new();
   // ImLexAnalyzer* p_la = (ImLexAnalyzer*)ImCnLexAnalyzer_new();

   HEGGDIRECTORY hDirectory = eggDirectory_open("/ape/ImRoBot5/index/bbstest");
   HEGGINDEXREADER hIndexReader = eggIndexReader_open(hDirectory);
   HEGGINDEXSEARCHER hIndexSearcher = eggIndexSearcher_new(hIndexReader);
   HEGGQUERY h1, h2, h3;
   h1 = eggQuery_new_string("title", "人", 3, ANALYZER_CWSLEX);
   //h2 = eggQuery_new_string("content", "new", 3, p_la);
   // h2 = eggQuery_new_string("body", "some description", 16, p_la);
   // h3 = eggQuery_new_int32("price", 199);
   // h2 = eggQuery_and(h3, h2);
   //h1 = eggQuery_or(h2, h1);
   // h3 = h2 = 0;
   HEGGTOPCOLLECTOR hTopCollector = eggTopCollector_new(0);
   int ret = eggIndexSearcher_search_with_query(hIndexSearcher, hTopCollector, h1);
   if (ret == EGG_TRUE)
   {
        eggTopCollector_normalized(hTopCollector, EGG_TOPSORT_SCORE);
        // eggTopCollector_normalized(hTopCollector, EGG_TOPSORT_NOT);
        HEGGSCOREDOC lp_score_doc = eggTopCollector_top_docs(hTopCollector);
        count_t cnt =  eggTopCollector_total_hits(hTopCollector);
        printf("have hit %u documents\n", cnt);

        if (cnt > 0)
        {
             printf("last document: id[%llu]\n", lp_score_doc[cnt-1].idDoc);
             HEGGDOCUMENT lp_eggDocument = EGG_NULL;
             eggIndexReader_get_document(hIndexReader,
                                lp_score_doc[cnt-1].idDoc, &lp_eggDocument);
             HEGGFIELD lp_field = eggDocument_get_field(lp_eggDocument,"title");
             unsigned len = 0;
             char *val = eggField_get_value(lp_field, &len);
             printf("last document: body[%.*s]\n", len, val);
             lp_field = 0;
             eggDocument_delete(lp_eggDocument);
        }
   }

   eggTopCollector_delete(hTopCollector);
   eggQuery_delete(h1);
   eggIndexSearcher_delete(hIndexSearcher);
   eggIndexReader_close(hIndexReader);
   eggDirectory_close(hDirectory);
   ImLexAnalyzer_delete(p_la);
}

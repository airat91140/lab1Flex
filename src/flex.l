%option noyywrap
%option c++
%x HASH TAIL

%%
<INITIAL>{
^(ed2k:\/\/\|file\|[A-Za-z+-_.]+\|[0-9]+\|) BEGIN(HASH);
\n return 0;
. ;
}
<HASH>{
(?i:[0-9a-f]{32}) {BEGIN(TAIL); return 1;}
. BEGIN(INITIAL);
\n {BEGIN(INITIAL); return 0;}
}
<TAIL>{
\|\/\n BEGIN(INITIAL);
}
%%


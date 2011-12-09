/*
-----------------------------------------------------------------------------
This source file is part of OSTIS (Open Semantic Technology for Intelligent Systems)
For the latest info, see http://www.ostis.net

Copyright (c) 2010 OSTIS

OSTIS is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

OSTIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with OSTIS.  If not, see <http://www.gnu.org/licenses/>.
-----------------------------------------------------------------------------
*/

/**
 * @file misc.h
 * @author ALK
 * @brief parser structures definition.
 */

 #ifndef __PARSER_H__
#define __PARSER_H__
#include <stdio.h>

#include "list.h"
#include "values.h"

struct _alink;
struct _textvalue;
struct _elink;
struct _slink;
struct _tval;

typedef struct _alink alink;
typedef struct _textvalue textvalue;
typedef struct _elink elink;
typedef struct _slink slink;
typedef struct _tval tval;

/* element list member */
struct _elink {
	struct list_head elist;
	int ref;
	/* valid for attributes only */
	int attr_con_type;
};

/* active element list member */
/* note that alink looks like elink. We can add alinks to elists */
struct _alink {
	struct list_head alist;
	int ref;
	/* valid for attributes only */
	int attr_con_type;
	/* elinks */
	struct list_head attr_list;
};

/* string list member */
struct _slink {
	struct list_head slist;
	char *str;
};

/* TermAttributes value type */
struct _tval {
	struct list_head aliases_list;
	struct list_head attr_list;
};

struct _textvalue {
	/* list of alinks */
	struct list_head active_list;
	/* list of elinks */
	struct list_head inact_list;
};

/* eliminates duplicated values */
/* this would be faster if we first sort this list */
int	elist_unify(struct list_head *head);

/* adds all information in act to inact elist */
/* destroys act list. does not free head */
void	actives_to_inactives(struct list_head *act,struct list_head *inact);

slink *	slink_new(char *str);

alink * alink_new(int ref);

void	text_init(textvalue *text);

int	text_new(textvalue **text);

void	text_move(textvalue *oldtext,textvalue *newtext);

void	text_add(textvalue *oldtext,textvalue *newtext);

int	rule_text(textvalue *text,textvalue *sent);

/* idents are added to sent. Some structures also made and added of course */
int	rule_sent(textvalue *sent,textvalue *idents,con_type con);

/* aliases are not supported yet */
/* term becomes ident */
int	rule_ident(slink *aliases,textvalue *attrs,textvalue *term);

/* keeps order in which aliases are written */
int	rule_aliases(slink *aliases,char *alias);

int	rule_term_id(char *id,textvalue **term);
int	rule_term_strcont(char *cont,textvalue **term);

/* must add to begin of list. rule_term_text depends on it */
int	add_elink_ref_begin(int ref,struct list_head *head);

/* text becomes term */
int	rule_term_text(textvalue *text,int constancy);

/* set becomes term */
int	rule_term_set(textvalue *set,int constancy);

/* no special checks yet */
int	rule_term_arc(textvalue *id1,con_type con,
				textvalue *id2,textvalue **term);

int	rule_term_base64cont(char *str,textvalue **term);
int	rule_term_number(char *str,textvalue **term);

int	assign_cont(textvalue *term,char *text,int cont_type);

/* interface to generated by bison parser */
extern	int yyparse(void);
/* interface to generated by flex scanner */
extern	int yylex(void);
extern	FILE *yyin;

extern char *cfilename;

extern int do_not_complain_constancy;

extern char *include_paths[]; /* NULL terminated array of includes */

#endif /* __PARSER_H__ */

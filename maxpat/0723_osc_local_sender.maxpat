{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 7,
			"minor" : 2,
			"revision" : 2,
			"architecture" : "x86",
			"modernui" : 1
		}
,
		"rect" : [ 1371.0, 79.0, 193.0, 367.0 ],
		"bglocked" : 0,
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-45",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 18.0, 190.0, 150.0, 32.0 ],
					"style" : "",
					"text" : "リハ、本番時には\nこれは消す"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-43",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 18.0, 238.0, 50.0, 22.0 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-41",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 18.0, 274.0, 93.0, 22.0 ],
					"style" : "",
					"text" : "prepend /scene"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-11",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 69.0, 57.0, 49.0, 22.0 ],
					"style" : "",
					"text" : "clearall"
				}

			}
, 			{
				"box" : 				{
					"bubblesize" : 15,
					"id" : "obj-109",
					"maxclass" : "preset",
					"numinlets" : 1,
					"numoutlets" : 4,
					"outlettype" : [ "preset", "int", "preset", "int" ],
					"patching_rect" : [ 18.0, 98.5, 100.0, 64.0 ],
					"preset_data" : [ 						{
							"number" : 1,
							"data" : [ 5, "obj-43", "number", "int", 0 ]
						}
, 						{
							"number" : 2,
							"data" : [ 5, "obj-43", "number", "int", 1 ]
						}
, 						{
							"number" : 3,
							"data" : [ 5, "obj-43", "number", "int", 2 ]
						}
, 						{
							"number" : 4,
							"data" : [ 5, "obj-43", "number", "int", 3 ]
						}
, 						{
							"number" : 5,
							"data" : [ 5, "obj-43", "number", "int", 4 ]
						}
, 						{
							"number" : 6,
							"data" : [ 5, "obj-43", "number", "int", 5 ]
						}
, 						{
							"number" : 7,
							"data" : [ 5, "obj-43", "number", "int", 6 ]
						}
, 						{
							"number" : 8,
							"data" : [ 5, "obj-43", "number", "int", 7 ]
						}
, 						{
							"number" : 9,
							"data" : [ 5, "obj-43", "number", "int", 8 ]
						}
, 						{
							"number" : 10,
							"data" : [ 5, "obj-43", "number", "int", 9 ]
						}
, 						{
							"number" : 11,
							"data" : [ 5, "obj-43", "number", "int", 10 ]
						}
, 						{
							"number" : 12,
							"data" : [ 5, "obj-43", "number", "int", 11 ]
						}
, 						{
							"number" : 13,
							"data" : [ 5, "obj-43", "number", "int", 12 ]
						}
, 						{
							"number" : 14,
							"data" : [ 5, "obj-43", "number", "int", 13 ]
						}
, 						{
							"number" : 15,
							"data" : [ 5, "obj-43", "number", "int", 14 ]
						}
 ],
					"style" : ""
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 1.0, 0.757085, 0.721077, 1.0 ],
					"fontsize" : 14.0,
					"id" : "obj-60",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 18.0, 23.5, 57.0, 22.0 ],
					"style" : "",
					"text" : "シーン"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 18.0, 308.5, 147.0, 22.0 ],
					"style" : "",
					"text" : "udpsend 127.0.0.1 12344"
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-109", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-41", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-41", 0 ],
					"disabled" : 0,
					"hidden" : 0,
					"source" : [ "obj-43", 0 ]
				}

			}
 ],
		"dependency_cache" : [  ],
		"autosave" : 0
	}

}
